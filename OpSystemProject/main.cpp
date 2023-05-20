//
//  main.cpp
//  OpSystemProject
//
//  Created by Mustafa Ceylan on 22.04.2023.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <ctime>

using namespace std;


enum SurecType
{
    nullSurec = 0,
    SüreçGeldi = 1,
    SüreçÇalışmayaBaşladı = 2,
    SüreçGÇİstedi = 3,
    SüreçGçBitti = 4,
    SüreçÇalışmayıBıraktı = 5,
    SüreçÇıktı = 6
};

class Surec{
public:
    int SurecId;
    SurecType SurecTipi;
    int BaslangicZamani;
    
    void setSurecId(int Id){
        this->SurecId = Id;
    }
    int getSurecId(){
        return this->SurecId;
    }
    
    void setBaslangicZamani(int zaman){
        this->BaslangicZamani = zaman;
    }
    int getBaslangicZamani(){
        return this->BaslangicZamani;
    }
    
    void setSurecType(SurecType surecType){
        this->SurecTipi = surecType;
    }
    
    SurecType getSurecType(){
        
        return  this->SurecTipi;
    }
    
    string getSurecDetail(){
        return EnumToStrig(this->SurecTipi);
    }
    
    string EnumToStrig(SurecType surec){
        
        switch (surec) {
            case 0:
                return "NULL";
                break;
            case 1:
                return "Geldi";
                break;
            case 2:
                return "Çalışmaya Başladı";
                break;
            case 3:
                return "GÇ İstedi";
                break;
                
            case 4:
                return "Gç Bitti";
                break;
                
            case 5:
                return "Çalışmayı Bıraktı";
                break;
                
            case 6:
                return "Çıktı";
                break;
            default:
                return "";
                break;
        }
    }
    
};

SurecType sonrakiDurum(SurecType mevcutDurum)
{
    switch (mevcutDurum)
    {
        case nullSurec:
            return SüreçGeldi;
        case SüreçGeldi:
            return SüreçÇalışmayaBaşladı;
        case SüreçÇalışmayaBaşladı:
            return SüreçGÇİstedi;
        case SüreçGÇİstedi:
            return SüreçGçBitti;
        case SüreçGçBitti:
            return SüreçÇalışmayıBıraktı;
        case SüreçÇalışmayıBıraktı:
            return SüreçÇıktı;
        default:
            return SüreçGeldi;
    }
}




int main(int argc, const char * argv[]) {
    
    srand( time(NULL));
    
    
    int maxRandomSystemTime = rand()%50 + 1; // toplam sürec zamanı 50sn ye kadar olsun
    int randomSurec = rand()%maxRandomSystemTime + 1; // random sürec uretme
    
    cout << "Random system time: " << maxRandomSystemTime << endl;
    cout << "Random sürec time:" << randomSurec << endl << endl;
    
    vector<Surec> surecler;
    vector<Surec> duzenlenmisSurecler;
    
//    Random süreçler oluşturuyoruz
    for(int i = 0 ; i < randomSurec; i++){
        
        int randomId = rand()%5 + 1;
        int randomSayı = rand()%maxRandomSystemTime;
        Surec sr;
        
        
        sr.setSurecId(randomId);
        sr.setBaslangicZamani(randomSayı);
        sr.setSurecType(nullSurec);
        surecler.push_back(sr);
        
    }
    
    
    
    sort(surecler.begin(),surecler.end(),[](const Surec& src1, const Surec& src2){
        return src1.BaslangicZamani <= src2.BaslangicZamani;
    });
    
//    aşagıdaki for dongulerınde süreclerin atamasını yapıyoruz kurallara göre
    for(int i = 1;i<=5;i++){
       
        for(int j =0;j<surecler.size();j++){
            if(surecler[j].getSurecId() == i){
                
                if(surecler[j].getSurecType() == nullSurec){
                    surecler[j].setSurecType(sonrakiDurum(nullSurec));
                    duzenlenmisSurecler.push_back(surecler[j]);
                    break;
                }

            }
        }
    }
    
    for(int i = 1;i<=5;i++){
       
        for(int j =0;j<surecler.size();j++){
            if(surecler[j].getSurecId() == i){
                
                if(surecler[j].getSurecType() == nullSurec){
                    surecler[j].setSurecType(sonrakiDurum(SüreçGeldi));
                    duzenlenmisSurecler.push_back(surecler[j]);
                    break;
                }

            }
        }
    }
    
    for(int i = 1;i<=5;i++){
       
        for(int j =0;j<surecler.size();j++){
            if(surecler[j].getSurecId() == i){
                
                if(surecler[j].getSurecType() == nullSurec){
                    surecler[j].setSurecType(sonrakiDurum(SüreçÇalışmayaBaşladı));
                    duzenlenmisSurecler.push_back(surecler[j]);
                    break;
                }

            }
        }
        
    }
    
    for(int i = 1;i<=5;i++){
       
        for(int j =0;j<surecler.size();j++){
            if(surecler[j].getSurecId() == i){
                
                if(surecler[j].getSurecType() == nullSurec){
                    surecler[j].setSurecType(sonrakiDurum(SüreçGÇİstedi));
                    duzenlenmisSurecler.push_back(surecler[j]);
                    break;
                }

            }
        }
    }
    
    for(int i = 1;i<=5;i++){
       
        for(int j =0;j<surecler.size();j++){
            if(surecler[j].getSurecId() == i){
                
                if(surecler[j].getSurecType() == nullSurec){
                    surecler[j].setSurecType(sonrakiDurum(SüreçGçBitti));
                    duzenlenmisSurecler.push_back(surecler[j]);
                    break;
                }

            }
        }
    }
    
    for(int i = 1;i<=5;i++){
       
        for(int j =0;j<surecler.size();j++){
            if(surecler[j].getSurecId() == i){
                
                if(surecler[j].getSurecType() == nullSurec){
                    surecler[j].setSurecType(sonrakiDurum(SüreçÇalışmayıBıraktı));
                    duzenlenmisSurecler.push_back(surecler[j]);
                    break;
                }

            }
        }
    }
    
//    sort(duzenlenmisSurecler.begin(),duzenlenmisSurecler.end(),[](const Surec& src1, const Surec& src2){
//        return src1.BaslangicZamani <= src2.BaslangicZamani;
//    });
    
    
    cout << endl;
    
    for(int i=0;i<duzenlenmisSurecler.size();i++){
        
        cout << "Zaman: " << duzenlenmisSurecler[i].getBaslangicZamani() << "s: Süreç " << duzenlenmisSurecler[i].getSurecId() << " " << duzenlenmisSurecler[i].getSurecDetail()<< endl;
        
    }
    
    
    
    return 0;
}
