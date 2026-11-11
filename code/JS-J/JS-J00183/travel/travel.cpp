#include<iostream>
#include<fstream>
int she[6]={1,2,3,5,5,6};
int main()
{
    std::ifstream fin("travel.in");
    std::ofstream fout("travel.out");
    char c11,c12,s11,s12,s13,c21,c22,s21,s22,s23;
    fin>>c11>>c12>>s11>>s12>>s13>>c21>>c22>>s21>>s22>>s23;
    if(c11==c21 && c12==c22)
    {
         fout<<"1";
        if(s11==s21 && s12==s22)
        {
            fout<<"1";
            if(('A'<=s13 && s13<='C' && 'A'<=s23 && s23<='C' ) || ('D'<=s13 && s13<='F' && 'D'<=s23 && s23<='F'))
            {
                fout<<"1";
                if(she[s13-'A']-she[s23-'A']==1 or she[s13-'A']-she[s23-'A']==-1)
                    fout<<"1";
                else fout<<"0";
            }
            else fout<<"00";
        }
        else fout<<"000";
    }
    else fout<<"0000";
}
