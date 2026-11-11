#include<fstream>
#include<string>
using namespace std;
ifstream fin("travel.in");
ofstream fout("travel.out");
int main(){
    string a,b,c,d;
    fin>>a>>b>>c>>d;
    if(a==c){
        fout<<1;
        if(b[0]==d[0] and b[1]==d[1]){
            fout<<1;
            if((b[2]<='C' and d[2]<='C') or (b[2]>'C' and d[2]>'C')){
                fout<<1;
                if((b[2]-d[2]==1 or d[2]-b[2]==1))fout<<1;
                else fout<<0;
            }else fout<<0<<0;
        }else fout<<0<<0<<0;
    }else fout<<0<<0<<0<<0;
    return 0;
}
