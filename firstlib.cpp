#include "firstlib.h";

//---------------------------------------------------------
double rezultatas(double suma, int kiekis, int egz)
{
    double rez = 0;
    try
    {
        if (kiekis == 0)
        {
            throw std::invalid_argument("Kiekis negali buti lygus nuliui");
        }
    }
    catch (const std::exception& e)
    {
        cout << "Dalyba is nulio. " << e.what() << endl;
    }
    rez = 0.4 * (suma / kiekis * 1.0) + 0.6 * egz;
    return rez;
}
//--------------------------------------------------------------

//--------------------------------------------------------------
double Med(vector<int> data)
{
    sort(data.begin(), data.end());
    size_t size = data.size();
    if (size % 2 == 0)
    {
        size_t middle = size / 2;
        return (data[middle - 1] + data[middle]) / 2.0;
    }
    else
    {
        return data[size / 2];
    }
}
//---------------------------------------------------------------

//---------------------------------------------------------------
double rezMed(double mediana, int egz)
{
    double rez = 0;
    rez = 0.4 * mediana + 0.6 * egz;
    return rez;
}
//----------------------------------------------------------------

//----------------------------------------------------------------
bool palyginimasVardai(const Studentas& studentas1, const Studentas& studentas2)
{
    return studentas1.getVardas() < studentas2.getVardas();
}
//-----------------------------------------------------------------

//-----------------------------------------------------------------
bool palyginimasPavardes(const Studentas& studentas1, const Studentas& studentas2)
{
    return studentas1.getPavarde() < studentas2.getPavarde();
}
//------------------------------------------------------------------

//------------------------------------------------------------------
bool palyginimasVidurkis(const Studentas& studentas1, const Studentas& studentas2)
{
    return studentas1.getGalutinis() < studentas2.getGalutinis();
}
//-------------------------------------------------------------------

//--------------------------------------------------------------------
void generavimas(int studentu_skaicius, string fileName, int nd_kiekis)
{
    srand(time(NULL));
    auto pradzia = std::chrono::high_resolution_clock::now();
    ofstream outputFile(fileName);
    outputFile << left << "Vardas" << setw(25) << " " << setw(13) << right << "Pavarde" << setw(15) << " ";
    for (int i = 0; i < nd_kiekis; i++)
    {
        outputFile << setw(3) << right << "ND" << setw(3) << left << i + 1 << setw(5) << " ";
    }
    outputFile << setw(7) << left << "Egz." << endl;
    for (int i = 0; i < studentu_skaicius; i++)
    {
        outputFile << left << "Vardas" << setw(10) << left << i + 1 << setw(15) << " " << setw(13) << right << "Pavarde" << setw(10) << left << i + 1;
        for (int j = 0; j < nd_kiekis; j++)
        {
            outputFile << setw(9) << right << rand() % 10 + 1 << setw(2) << right << " ";
        }
        outputFile << setw(9) << right << rand() % 10 + 1 << endl;
    }
    outputFile.close();
    auto pabaiga = std::chrono::high_resolution_clock::now();
    auto uztruko = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia);
    cout << "Failo " << fileName << " generavimo laikas:" << uztruko.count() << " milisekundziu" << endl;
}
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
void isvedimas(vector<Studentas> studentai, string fileName)
{
    ofstream outputFile(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Failo atidarymo klaida: " << fileName << endl;
        return;
    }
    outputFile << setw(20) << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(Vid.)" << endl;
    outputFile << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < studentai.size(); i++)
    {
        outputFile << setw(20) << left << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(20) << fixed << setprecision(2) << studentai[i].getGalutinis() << endl;
    }
    outputFile.close();
}
//---------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------
void skaitymas(vector<Studentas>& studentai, string Fname)
{
    studentai.clear();
    ifstream input_file(Fname);
    if (!input_file.is_open())
    {
        cout << "Failo atidarymas negalimas: " << Fname << endl;
        exit(1);
    }
    string header;
    int stulp_kiekis = 0;
    getline(input_file, header);
    string vardas;
    string pavarde;
    std::istringstream headerStream(header);
    string token;
    while (headerStream >> token)
    {
        stulp_kiekis++;
    }
    while (input_file >> vardas >> pavarde)
    {
        double nd_suma = 0.0;
        Studentas naujas_st;
        naujas_st.setVardas(vardas);
        naujas_st.setPavarde(pavarde);
        for (int i = 0; i < stulp_kiekis - 3; i++)
        {
            int nd;
            if (!(input_file >> nd) || (nd > 10) || (nd < 0))
            {
                cout << "Nepavyko perskaityti namu darbo rezultato is failo." << endl;
                cout << "Tarp duomenu yra netikslumu, pvz. namu darbo pazymys didesnis uz 10 arba vietoj pazymio irasyta raide." << endl;
                exit(1);
            }
            naujas_st.addND(nd);
        }
        int Egz;
        if (!(input_file >> Egz) || (Egz > 10) || (Egz < 0))
        {
            cout << "Nepavyko perskaityti egzamino rezultato is failo." << endl;
            cout << "Tarp duomenu yra netikslumu, pvz. egzamino pazymys didesnis uz 10 arba vietoj pazymio irasyta raide." << endl;
            exit(1);
        }
        naujas_st.setEgzaminas(Egz);
        nd_suma = accumulate(naujas_st.getND().begin(), naujas_st.getND().end(), 0.0);
        naujas_st.setGalutinis(rezultatas(nd_suma, naujas_st.getND().size(), naujas_st.getEgz()));
        studentai.push_back(naujas_st);
        naujas_st.getND().clear();
    }
}
//------------------------------------------------------------------------------------------------------
bool Vargsiukai(const Studentas& studentas, double riba)
{
    return studentas.getGalutinis() < riba;
}
//-------------------------------------------------------------------------------------------------------

