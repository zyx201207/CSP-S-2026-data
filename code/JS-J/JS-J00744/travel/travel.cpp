#include<fstream>
std::ifstream fin("travel.in");
std::ofstream fout("travel.out");
int main(){
    std::string a,b,c,d;
    fin>>a>>b>>c>>d;
    if(a==c){
        fout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            fout<<1;
            if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
                fout<<1;
                if(d[2]<b[2]){
                    std::swap(d[2],b[2]);
                }
                if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')){
                    fout<<1;
                }else{
                    fout<<0;
                }
            }else{
                fout<<"00";
            }
        }else{
            fout<<"000";
        }
    }else{
        fout<<"0000";
    }

}
