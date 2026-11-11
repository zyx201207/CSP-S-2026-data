#include<bits/stdc++.h>
std::ifstream fin("travel.in");
std::ofstream fout("travel.out");
int main(){
    std::string a,b,c,d;
    fin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1]){
        fout<<"1";
        if(b[0]==d[0]&&b[1]==d[1]){
            fout<<"1";
            if((b[2]=='D'&&d[2]=='F') || (b[2]=='F'&&d[2]=='D')){
                fout<<"11";
            }
            else if((b[2]=='A'&&d[2]<='A'+2)||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&d[2]>='C'-2&&d[2]<='C')){
                fout<<"1";
                if(b[2]-d[2]==1||d[2]-b[2]==1){
                    fout<<"1";
                }
                else{
                    fout<<"0";
                }
            }
            else{
                fout<<"00";
            }
        }
        else{
            fout<<"000";
        }
    }
    else{
        fout<<"0000";
    }
}
