#include "firstlib.h"

int main()
{
    /*Studentas studentas2;
    cin>>studentas2;
    Studentas studentas3(studentas2);
    Studentas studentas4;
    studentas4=studentas3;
    cout<<studentas2<<endl;
    cout<<studentas3<<endl;
    cout<<studentas4<<endl;*/
    cout << "Ar norite sugeneruoti faila? Jeigu taip - rasykite 'T', jeigu ne - 'N'." << endl;
    char pasirinkimas5;
    cin >> pasirinkimas5;
    if (pasirinkimas5 == 'T' || pasirinkimas5 == 't')
    {
        cout << "Iveskite studentu skaiciu" << endl;
        int studentu_sk;
        cin >> studentu_sk;
        cout << "Iveskite failo pavadinima" << endl;
        string failoPav;
        cin >> failoPav;
        cout << "Iveskite namu darbu kieki" << endl;
        int namuDarbu_kiekis;
        cin >> namuDarbu_kiekis;
        generavimas(studentu_sk, failoPav, namuDarbu_kiekis);
        cout << "Ar norite baigti darba? Jeigu taip - rasykite 'T', jeigu ne - 'N'." << endl;
        char pasirinkimas7;
        cin >> pasirinkimas7;
        if (pasirinkimas7 == 'T' || pasirinkimas7 == 't')
        {
            return 1;
        }
    }
    cout << "Ar norite testuoti skaitymo, rusiavimo ir isvedimo laika? Jeigu taip - rasykite 'T', jeigu ne - 'N'." << endl;
    char pasirinkimas8;
    cin >> pasirinkimas8;
    cout << "Kokia strategija norite panaudoti? Jeigu 1 rasykite 'P', jeigu 2 - 'A', jeigu 3 - 'T'." << endl;
    char pasirinkimas10;
    cin >> pasirinkimas10;
    if (pasirinkimas8 == 'T' || pasirinkimas8 == 't')
    {
        if (pasirinkimas10 == 'P' || pasirinkimas10 == 'p')
        {
            vector <Studentas> studentai;
            vector <Studentas> vargsiukai;
            vector <Studentas> kietiakiai;
            std::chrono::milliseconds sumaSkaitymas = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRusiavimas = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaSortVargsiukai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaSortKietiakai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRasymasVargsiukai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRasymasKietiakai = std::chrono::milliseconds::zero();
            cout << "Iveskite failo pavadinima." << endl;
            string failoPav;
            cin >> failoPav;
            cout << "Kiek kartu norite perskaityti faila ir surusiuoti?" << endl;
            int skaitk;
            cin >> skaitk;
            double riba = 5.0;
            cout << "Pasirinkite buda, kaip surusioti rezultatus. Jeigu norite rusiuoti pagal varda, rasykite 'V', jeigu pagal pavarde - 'P', pagal vidurki 'A'" << endl;
            char pasirinkimas9;
            cin >> pasirinkimas9;
            for (int i = 0; i < skaitk; i++)
            {
                vargsiukai.clear();
                kietiakiai.clear();
                auto pradzia = std::chrono::high_resolution_clock::now();
                skaitymas(studentai, failoPav);
                auto pabaiga = std::chrono::high_resolution_clock::now();
                auto uztruko = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia);
                cout << "Failo " << failoPav << " skaitymo laikas:" << uztruko.count() << " milisekundziu" << endl;
                sumaSkaitymas = sumaSkaitymas + uztruko;
                auto pradzia4 = std::chrono::high_resolution_clock::now();
                for (int i = 0; i < studentai.size(); i++)
                {
                    if (studentai[i].getGalutinis() < riba)
                    {
                        vargsiukai.push_back(studentai[i]);
                    }
                    else
                    {
                        kietiakiai.push_back(studentai[i]);
                    }
                }
                auto pabaiga4 = std::chrono::high_resolution_clock::now();
                auto uztruko4 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga4 - pradzia4);
                cout << "Rusiavimo i grupes laikas:" << uztruko4.count() << " milisekundziu" << endl;
                sumaRusiavimas = sumaRusiavimas + uztruko4;
                if (pasirinkimas9 == 'V' || pasirinkimas9 == 'v')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasVardai);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(kietiakiai.begin(), kietiakiai.end(), palyginimasVardai);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal varda uztruko " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal varda uztruko " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else if (pasirinkimas9 == 'P' || pasirinkimas9 == 'p')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasPavardes);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(kietiakiai.begin(), kietiakiai.end(), palyginimasPavardes);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal pavarde uztruko " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal pavarde uztruko " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else if (pasirinkimas9 == 'A' || pasirinkimas9 == 'a')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasVidurkis);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(kietiakiai.begin(), kietiakiai.end(), palyginimasVidurkis);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal pavarde vidurki " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal pavarde vidurki " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else
                {
                    cout << "Netinkamas pasirinkimas" << endl;
                    return 1;
                }
                auto pradzia5 = std::chrono::high_resolution_clock::now();
                isvedimas(vargsiukai, "vargsiukai.txt");
                auto pabaiga5 = std::chrono::high_resolution_clock::now();
                auto uztruko5 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga5 - pradzia5);
                cout << "Failo " << "vargsiukai.txt" << " isvedimo laikas:" << uztruko5.count() << " milisekundziu" << endl;
                sumaRasymasVargsiukai = sumaRasymasVargsiukai + uztruko5;
                auto pradzia6 = std::chrono::high_resolution_clock::now();
                isvedimas(kietiakiai, "kietiakiai.txt");
                auto pabaiga6 = std::chrono::high_resolution_clock::now();
                auto uztruko6 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga6 - pradzia6);
                cout << "Failo " << "kietiakiai.txt" << " isvedimo laikas:" << uztruko6.count() << " milisekundziu" << endl;
                sumaRasymasKietiakai = sumaRasymasKietiakai + uztruko6;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            double vidurkisSkaitymas = static_cast<double>(sumaSkaitymas.count()) / skaitk;
            double vidurkisRusiavimas = static_cast<double>(sumaRusiavimas.count()) / skaitk;
            double vidurkisSortVargsiukai = static_cast<double>(sumaSortVargsiukai.count()) / skaitk;
            double vidurkisSortKietiakai = static_cast<double>(sumaSortKietiakai.count()) / skaitk;
            double vidurkisRasymasVargsiukai = static_cast<double>(sumaRasymasVargsiukai.count()) / skaitk;
            double vidurkisRasymasKietiakai = static_cast<double>(sumaRasymasKietiakai.count()) / skaitk;
            cout << "Skaitymo laiko vidurkis: " << vidurkisSkaitymas << " milisekundziu" << endl;
            cout << "Rusiavimo laiko vidurkis: " << vidurkisRusiavimas << " milisekundziu" << endl;
            cout << "VargsiukaiSort laiko vidurkis: " << vidurkisSortVargsiukai << " milisekundziu" << endl;
            cout << "KietiakaiSort laiko vidurkis: " << vidurkisSortKietiakai << " milisekundziu" << endl;
            cout << "Rasymo i Vargsiukai faila laiko vidurkis: " << vidurkisRasymasVargsiukai << " milisekundziu" << endl;
            cout << "Rasymo i Kietiakai faila laiko vidurkis: " << vidurkisRasymasKietiakai << " milisekundziu" << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl;
            cout << "Ar norite pabaigti darba? Jeigu taip rasykite 'T', jeigu ne - 'N'" << endl;
            char pasirinkimas6;
            cin >> pasirinkimas6;
            if (pasirinkimas6 == 'T' || pasirinkimas6 == 't')
            {
                return 1;
            }
        }
        else if (pasirinkimas10 == 'A' || pasirinkimas10 == 'a')
        {
            vector <Studentas> studentai;
            vector <Studentas> vargsiukai;
            std::chrono::milliseconds sumaSkaitymas = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRusiavimas = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaSortVargsiukai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaSortKietiakai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRasymasVargsiukai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRasymasKietiakai = std::chrono::milliseconds::zero();
            cout << "Iveskite failo pavadinima." << endl;
            string failoPav;
            cin >> failoPav;
            cout << "Kiek kartu norite perskaityti faila ir surusiuoti?" << endl;
            int skaitk;
            cin >> skaitk;
            double riba = 5.0;
            cout << "Pasirinkite buda, kaip surusioti rezultatus. Jeigu norite rusiuoti pagal varda, rasykite 'V', jeigu pagal pavarde - 'P', pagal vidurki 'A'" << endl;
            char pasirinkimas9;
            cin >> pasirinkimas9;
            for (int i = 0; i < skaitk; i++)
            {
                vargsiukai.clear();
                studentai.clear();
                auto pradzia = std::chrono::high_resolution_clock::now();
                skaitymas(studentai, failoPav);
                auto pabaiga = std::chrono::high_resolution_clock::now();
                auto uztruko = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia);
                cout << "Failo " << failoPav << " skaitymo laikas:" << uztruko.count() << " milisekundziu" << endl;
                sumaSkaitymas = sumaSkaitymas + uztruko;
                auto pradzia4 = std::chrono::high_resolution_clock::now();
                sort(studentai.rbegin(), studentai.rend(), [](const Studentas& a, const Studentas& b)
                    {
                        return a.getGalutinis() < b.getGalutinis();
                    });
                while (!studentai.empty() && studentai.back().getGalutinis() < riba)
                {
                    vargsiukai.push_back(studentai.back());
                    studentai.pop_back();
                }
                auto pabaiga4 = std::chrono::high_resolution_clock::now();
                auto uztruko4 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga4 - pradzia4);
                cout << "Rusiavimo i grupes laikas:" << uztruko4.count() << " milisekundziu" << endl;
                sumaRusiavimas = sumaRusiavimas + uztruko4;
                if (pasirinkimas9 == 'V' || pasirinkimas9 == 'v')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasVardai);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(studentai.begin(), studentai.end(), palyginimasVardai);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal varda uztruko " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal varda uztruko " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else if (pasirinkimas9 == 'P' || pasirinkimas9 == 'p')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasPavardes);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(studentai.begin(), studentai.end(), palyginimasPavardes);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal pavarde uztruko " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal pavarde uztruko " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else if (pasirinkimas9 == 'A' || pasirinkimas9 == 'a')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasVidurkis);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(studentai.begin(), studentai.end(), palyginimasVidurkis);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal pavarde vidurki " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal pavarde vidurki " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else
                {
                    cout << "Netinkamas pasirinkimas" << endl;
                    return 1;
                }
                auto pradzia5 = std::chrono::high_resolution_clock::now();
                isvedimas(vargsiukai, "vargsiukai.txt");
                auto pabaiga5 = std::chrono::high_resolution_clock::now();
                auto uztruko5 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga5 - pradzia5);
                cout << "Failo " << "vargsiukai.txt" << " isvedimo laikas:" << uztruko5.count() << " milisekundziu" << endl;
                sumaRasymasVargsiukai = sumaRasymasVargsiukai + uztruko5;
                auto pradzia6 = std::chrono::high_resolution_clock::now();
                isvedimas(studentai, "kietiakiai.txt");
                auto pabaiga6 = std::chrono::high_resolution_clock::now();
                auto uztruko6 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga6 - pradzia6);
                cout << "Failo " << "kietiakiai.txt" << " isvedimo laikas:" << uztruko6.count() << " milisekundziu" << endl;
                sumaRasymasKietiakai = sumaRasymasKietiakai + uztruko6;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            double vidurkisSkaitymas = static_cast<double>(sumaSkaitymas.count()) / skaitk;
            double vidurkisRusiavimas = static_cast<double>(sumaRusiavimas.count()) / skaitk;
            double vidurkisSortVargsiukai = static_cast<double>(sumaSortVargsiukai.count()) / skaitk;
            double vidurkisSortKietiakai = static_cast<double>(sumaSortKietiakai.count()) / skaitk;
            double vidurkisRasymasVargsiukai = static_cast<double>(sumaRasymasVargsiukai.count()) / skaitk;
            double vidurkisRasymasKietiakai = static_cast<double>(sumaRasymasKietiakai.count()) / skaitk;
            cout << "Skaitymo laiko vidurkis: " << vidurkisSkaitymas << " milisekundziu" << endl;
            cout << "Rusiavimo laiko vidurkis: " << vidurkisRusiavimas << " milisekundziu" << endl;
            cout << "VargsiukaiSort laiko vidurkis: " << vidurkisSortVargsiukai << " milisekundziu" << endl;
            cout << "KietiakaiSort laiko vidurkis: " << vidurkisSortKietiakai << " milisekundziu" << endl;
            cout << "Rasymo i Vargsiukai faila laiko vidurkis: " << vidurkisRasymasVargsiukai << " milisekundziu" << endl;
            cout << "Rasymo i Kietiakai faila laiko vidurkis: " << vidurkisRasymasKietiakai << " milisekundziu" << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl;
            cout << "Ar norite pabaigti darba? Jeigu taip rasykite 'T', jeigu ne - 'N'" << endl;
            char pasirinkimas6;
            cin >> pasirinkimas6;
            if (pasirinkimas6 == 'T' || pasirinkimas6 == 't')
            {
                return 1;
            }
        }
        else if (pasirinkimas10 == 'T' || pasirinkimas10 == 't')
        {
            vector <Studentas> studentai;
            vector <Studentas> vargsiukai;
            vector <Studentas> kietiakai;
            std::chrono::milliseconds sumaSkaitymas = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRusiavimas = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaSortVargsiukai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaSortKietiakai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRasymasVargsiukai = std::chrono::milliseconds::zero();
            std::chrono::milliseconds sumaRasymasKietiakai = std::chrono::milliseconds::zero();
            cout << "Iveskite failo pavadinima." << endl;
            string failoPav;
            cin >> failoPav;
            cout << "Kiek kartu norite perskaityti faila ir surusiuoti?" << endl;
            int skaitk;
            cin >> skaitk;
            double riba = 5.0;
            cout << "Pasirinkite buda, kaip surusioti rezultatus. Jeigu norite rusiuoti pagal varda, rasykite 'V', jeigu pagal pavarde - 'P', pagal vidurki 'A'" << endl;
            char pasirinkimas9;
            cin >> pasirinkimas9;
            for (int i = 0; i < skaitk; i++)
            {
                vargsiukai.clear();
                kietiakai.clear();
                auto pradzia = std::chrono::high_resolution_clock::now();
                skaitymas(studentai, failoPav);
                auto pabaiga = std::chrono::high_resolution_clock::now();
                auto uztruko = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga - pradzia);
                cout << "Failo " << failoPav << " skaitymo laikas:" << uztruko.count() << " milisekundziu" << endl;
                sumaSkaitymas = sumaSkaitymas + uztruko;
                vargsiukai.reserve(studentai.size());
                kietiakai.reserve(studentai.size());
                auto pradzia4 = std::chrono::high_resolution_clock::now();
                auto dalijimoTaskas = std::partition(studentai.begin(), studentai.end(), [riba](const Studentas& studentas)
                    {
                        return Vargsiukai(studentas, riba);
                    });
                std::copy(studentai.begin(), dalijimoTaskas, std::back_inserter(vargsiukai));
                std::copy(dalijimoTaskas, studentai.end(), std::back_inserter(kietiakai));
                auto pabaiga4 = std::chrono::high_resolution_clock::now();
                auto uztruko4 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga4 - pradzia4);
                cout << "Rusiavimo i grupes laikas:" << uztruko4.count() << " milisekundziu" << endl;
                sumaRusiavimas = sumaRusiavimas + uztruko4;
                if (pasirinkimas9 == 'V' || pasirinkimas9 == 'v')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasVardai);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(kietiakai.begin(), kietiakai.end(), palyginimasVardai);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal varda uztruko " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal varda uztruko " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else if (pasirinkimas9 == 'P' || pasirinkimas9 == 'p')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasPavardes);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(kietiakai.begin(), kietiakai.end(), palyginimasPavardes);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal pavarde uztruko " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal pavarde uztruko " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else if (pasirinkimas9 == 'A' || pasirinkimas9 == 'a')
                {
                    auto pradzia2 = std::chrono::high_resolution_clock::now();
                    sort(vargsiukai.begin(), vargsiukai.end(), palyginimasVidurkis);
                    auto pabaiga2 = std::chrono::high_resolution_clock::now();
                    auto uztruko2 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga2 - pradzia2);
                    auto pradzia3 = std::chrono::high_resolution_clock::now();
                    sort(kietiakai.begin(), kietiakai.end(), palyginimasVidurkis);
                    auto pabaiga3 = std::chrono::high_resolution_clock::now();
                    auto uztruko3 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga3 - pradzia3);
                    cout << "Vargsiuku rusiavimas pagal pavarde vidurki " << uztruko2.count() << " milisekundziu" << endl;
                    cout << "Kietiaku rusiavimas pagal pavarde vidurki " << uztruko3.count() << " milisekundziu" << endl;
                    sumaSortKietiakai = sumaSortKietiakai + uztruko3;
                    sumaSortVargsiukai = sumaSortVargsiukai + uztruko2;
                }
                else
                {
                    cout << "Netinkamas pasirinkimas" << endl;
                    return 1;
                }
                auto pradzia5 = std::chrono::high_resolution_clock::now();
                isvedimas(vargsiukai, "vargsiukai.txt");
                auto pabaiga5 = std::chrono::high_resolution_clock::now();
                auto uztruko5 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga5 - pradzia5);
                cout << "Failo " << "vargsiukai.txt" << " isvedimo laikas:" << uztruko5.count() << " milisekundziu" << endl;
                sumaRasymasVargsiukai = sumaRasymasVargsiukai + uztruko5;
                auto pradzia6 = std::chrono::high_resolution_clock::now();
                isvedimas(kietiakai, "kietiakiai.txt");
                auto pabaiga6 = std::chrono::high_resolution_clock::now();
                auto uztruko6 = std::chrono::duration_cast<std::chrono::milliseconds>(pabaiga6 - pradzia6);
                cout << "Failo " << "kietiakiai.txt" << " isvedimo laikas:" << uztruko6.count() << " milisekundziu" << endl;
                sumaRasymasKietiakai = sumaRasymasKietiakai + uztruko6;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            double vidurkisSkaitymas = static_cast<double>(sumaSkaitymas.count()) / skaitk;
            double vidurkisRusiavimas = static_cast<double>(sumaRusiavimas.count()) / skaitk;
            double vidurkisSortVargsiukai = static_cast<double>(sumaSortVargsiukai.count()) / skaitk;
            double vidurkisSortKietiakai = static_cast<double>(sumaSortKietiakai.count()) / skaitk;
            double vidurkisRasymasVargsiukai = static_cast<double>(sumaRasymasVargsiukai.count()) / skaitk;
            double vidurkisRasymasKietiakai = static_cast<double>(sumaRasymasKietiakai.count()) / skaitk;
            cout << "Skaitymo laiko vidurkis: " << vidurkisSkaitymas << " milisekundziu" << endl;
            cout << "Rusiavimo laiko vidurkis: " << vidurkisRusiavimas << " milisekundziu" << endl;
            cout << "VargsiukaiSort laiko vidurkis: " << vidurkisSortVargsiukai << " milisekundziu" << endl;
            cout << "KietiakaiSort laiko vidurkis: " << vidurkisSortKietiakai << " milisekundziu" << endl;
            cout << "Rasymo i Vargsiukai faila laiko vidurkis: " << vidurkisRasymasVargsiukai << " milisekundziu" << endl;
            cout << "Rasymo i Kietiakai faila laiko vidurkis: " << vidurkisRasymasKietiakai << " milisekundziu" << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl;
            cout << "Ar norite pabaigti darba? Jeigu taip rasykite 'T', jeigu ne - 'N'" << endl;
            char pasirinkimas6;
            cin >> pasirinkimas6;
            if (pasirinkimas6 == 'T' || pasirinkimas6 == 't')
            {
                return 1;
            }

        }
        else
        {
            cout << "Netinkamas pasirinkimas." << endl;
            return 1;
        }
    }
    vector <Studentas> studentai;
    Studentas naujas_st;
    /*Zmogus zmones;
    Zmogus zmogus("Cipsas", "Kebabas");*/
    int stud_sk = 0;
    cout << "Pasirinkite buda, kaip pildysite duomenys. Jeigu norit ivesti patys rasykite 'P', jeigu norite nuskaityti is failo - 'F'" << endl;
    char pasirinkimas3;
    cin >> pasirinkimas3;
    //------------------------------------------------Duomenu ivedimas----------------------------------------------------------------------------------

    if (pasirinkimas3 == 'P' || pasirinkimas3 == 'p')
    {
        cout << "Iveskite studentu skaiciu" << endl;
        cin >> stud_sk;
        if (stud_sk <= 0)
        {
            cerr << "Studentu skaicius turi buti didesnis uz 0." << endl;
            return 1;
        }
        for (int i = 0; i < stud_sk; i++)
        {
            cin >> naujas_st;
            studentai.push_back(naujas_st);
        }
    }
    else if (pasirinkimas3 == 'F' || pasirinkimas3 == 'f')
    {
        string Fname;
        cout << "Iveskite failo pavadinima su '.txt'" << endl;
        cin >> Fname;
        ifstream input_file(Fname);
        if (!input_file.is_open())
        {
            cout << "Failo atidarymas negalimas: " << Fname << endl;
            return 1;
        }
        string header;
        int stulp_kiekis = 0;
        getline(input_file, header);
        string v;
        string p;
        std::istringstream headerStream(header);
        string token;
        while (headerStream >> token)
        {
            stulp_kiekis++;
        }
        while (input_file >> v >> p)
        {
            Studentas naujas_st;
            naujas_st.setVardas(v);
            naujas_st.setPavarde(p);
            for (int i = 0; i < stulp_kiekis - 3; i++)
            {
                int nd;
                if (!(input_file >> nd) || (nd > 10) || (nd < 0))
                {
                    cout << "Nepavyko perskaityti namu darbo rezultato is failo." << endl;
                    cout << "Tarp duomenu yra netikslumu, pvz. namu darbo pazymys didesnis uz 10 arba vietoj pazymio irasyta raide." << endl;
                    return 1;
                }
                naujas_st.addND(nd);
            }
            int Egz;
            if (!(input_file >> Egz) || (Egz > 10) || (Egz < 0))
            {
                cout << "Nepavyko perskaityti egzamino rezultato is failo." << endl;
                cout << "Tarp duomenu yra netikslumu, pvz. egzamino pazymys didesnis uz 10 arba vietoj pazymio irasyta raide." << endl;
                return 1;
            }
            naujas_st.setEgzaminas(Egz);
            double nd_suma = accumulate(naujas_st.getND().begin(), naujas_st.getND().end(), 0.0);
            naujas_st.setGalutinis(rezultatas(nd_suma, naujas_st.getND().size(), naujas_st.getEgz()));
            double mediana = Med(naujas_st.getND());
            naujas_st.setGalutinisMediana(rezMed(mediana, naujas_st.getEgz()));
            studentai.push_back(naujas_st);
            stud_sk++;
            naujas_st.getND().clear();
        }
        input_file.close();
    }
    /*ifstream input_File;
    string Fname;
    cin>>Fname;
    input_File.open(Fname);
    if (!input_File.is_open())
    {
        cout << "Failo atidarymas negalimas: " << Fname << endl;
        return -1;
    }
    string Eil;
    getline(input_File, Eil);
    while(input_File)
    {
        if(!input_File.eof())
        {
            getline(input_File, Eil);
            input_File>>naujas_st;
            string Teil;
            input_File>>Teil; naujas_st.setVardas(Teil);
            input_File>>Teil; naujas_st.setPavarde(Teil);
            vector <int> LaikPaz;
            int t;
            while(input_File>>t)
            {
                if(t>=0 && t<11) naujas_st.addND(t);
                else cerr <<"Neteisingas pazymys:"<<endl;
            }
            if(LaikPaz.empty()) cerr<<"Studentas be pazymiu"<<endl;
            else
            {
                naujas_st.setEgzaminas(LaikPaz.back());
                naujas_st.ND.pop_back();
                studentai.push_back(naujas_st);
            }
            LaikPaz.clear();
            naujas_st.addND(LaikPaz);

        }
        else break;
    }
    input_File.close();*/

    else
    {
        cout << "Neteisingas pasirinkimas" << endl;
        return 1;
    }
    sort(studentai.begin(), studentai.end(), palyginimasVardai);
    char pasirinkimas;
    cout << "Jeigu norite gauti galutini bala su vidurkiu - parasykite 'V' raide, jeigu su mediana - 'M'" << endl;
    cin >> pasirinkimas;
    //---------------------------------------------------------Duomenu isvedimas----------------------------------------------------------
    char pasirinkimas4;
    cout << "Jeigu norite gauti rezultata ekrane rasykite 'E', jeigu faile 'F'" << endl;
    cin >> pasirinkimas4;
    if (pasirinkimas4 == 'E' || pasirinkimas4 == 'e')
    {
        cout << setw(20) << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << left;
        if (pasirinkimas == 'V' || pasirinkimas == 'v')
        {
            cout << "Galutinis(Vid.)" << endl;
        }
        else if (pasirinkimas == 'M' || pasirinkimas == 'm')
        {
            cout << "Galutinis(Med.)" << endl;
        }
        else
        {
            cout << "Neteisingas pasirinkimas";
            return 1;
        }
        cout << "------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < studentai.size(); i++)
        {
            cout << studentai[i];
        }
        cout << "--------------------------------------------------" << endl;
        for (auto& studentas : studentai)
        {
            cout << "Objekto saugojimo atmintyje adresas studento " << studentas.getVardas() << " " << studentas.getPavarde() << ": " << &studentas << endl;
        }
    }
    else if (pasirinkimas4 == 'F' || pasirinkimas4 == 'f')
    {
        ofstream outputFile("rezultatai.txt");
        outputFile << setw(20) << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << left;
        if (pasirinkimas == 'V' || pasirinkimas == 'v')
        {
            outputFile << "Galutinis(Vid.)" << endl;
        }
        else if (pasirinkimas == 'M' || pasirinkimas == 'm')
        {
            outputFile << "Galutinis(Med.)" << endl;
        }
        else
        {
            cout << "Neteisingas pasirinkimas";
            return 1;
        }
        outputFile << "------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < studentai.size(); i++)
        {
            outputFile << setw(20) << left << studentai[i].getVardas() << setw(20) << left << studentai[i].getPavarde() << setw(20) << left;
            if (pasirinkimas == 'V' || pasirinkimas == 'v')
            {
                outputFile << fixed << setprecision(2) << studentai[i].getGalutinis() << endl;
            }
            else    outputFile << fixed << setprecision(2) << studentai[i].getGalutinisMediana() << endl;
        }
        outputFile.close();
    }
    return 0;
}
