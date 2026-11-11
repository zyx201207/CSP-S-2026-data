#include<fstream>
std::ifstream fin("travel.in");
std::ofstream fout("travel.out");
std::string c,cc;
std::string s,ss;
int main()
{
    fin>>c>>s>>cc>>ss;
    if(c[0]==cc[0] && c[1]==cc[1]){
        fout<<1;
        if(s[0]==ss[0] && s[1]==ss[1]){
            fout<<1;
            if((s[2]=='A' && ss[2]=='B') || (s[2]=='A' && ss[2]=='C')){
                fout<<1;
                if((s[2]=='A' && ss[2]=='B'))fout<<1;
                else fout<<0;
            }
            else if((s[2]=='B' && ss[2]=='A')|| (s[2]=='B' && ss[2]=='C')){
                fout<<"11";
            }
            else if((s[2]=='C' && ss[2]=='B') || (s[2]=='C' && ss[2]=='A')){
                fout<<"1";
                if(s[2]=='C' && ss[2]=='B')fout<<1;
                else fout<<"0";
            }
            else if((s[2]=='D' && ss[2]=='E') || (s[2]=='E' && ss[2]=='D')){
                fout<<"11";
            }
            else fout<<"00";
        }
        else fout<<"000";
    }
    else fout<<"0000";
}
