#include<fstream>
#include<string>
int main(){
    std::ifstream fin("travel.in");
    std::ofstream fout("travel.out");
    std::string s;
    std::string a,c;
    for(int i=1;i<=a.size();i++){
        fin>>s;
        fin>>a>>c;
    }
    if(s[1]==s[2]){
        fout<<"1";
        if(a[1]==a[2]){
            fout<<"1";
            if(((c[2]!='C' && c[1]!='D')) || (c[1]!='C' && c[2]!='D')){
                fout<<"1";
                if(c[1]+1==c[2] || c[1]-1==c[2]){
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
