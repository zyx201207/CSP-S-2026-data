#include<fstream>
#include<string>
std::ifstream fin("travel.in");
std::ofstream fout("travel.out");
int main(){
   int a1,a2;
   std::string s1,s2;
   fin>>a1>>s1>>a2>>s2;
   if(a1==a2){
        fout<<1;
        int x1,x2,y1,y2;
        x1=(s1[0]-'0')*10+s1[1]-'0';
        y1=s1[2]-'A';
        x2=(s2[0]-'0')*10+s2[1]-'0';
        y2=s2[2]-'A';
        if(x1==x2){
            fout<<1;
            if(3<=y1&&y1<=4&&3<=y2&&y2<=4||0<=y1&&y1<=2&&0<=y2&&y2<=2){
                fout<<1;
                if(std::abs(y1-y2)==1)
                    fout<<1;
                else
                    fout<<0;
            }else
                fout<<"00";
        }else
            fout<<"000";
   }else
        fout<<"0000";
}
