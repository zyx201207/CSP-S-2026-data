#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[3],b[3];
int main()
{
    ifstream fin("travel.in");
    ofstream fout("travel.out");
    fin>>n>>a[0]>>a[1]>>a[2]>>m>>b[0]>>b[1]>>b[2];
    if(n!=m){
        fout<<"0000";
    }
    else{
        fout<<"1";
        if(a[0]!=b[0]||a[1]!=b[1]){
            fout<<"000";
        }
        else{
            fout<<"1";
            if(('C'>=a[2]&&b[2]>'C')||'C'>=b[2]&&a[2]>'C'){
                fout<<"00";
            }
            else{
                fout<<"1";
                if((a[2]=='C'&&b[2]=='A')||b[2]=='C'&&a[2]=='A'){
                    fout<<"0";
                }
                else{
                    fout<<"1";
                }
            }
        }
    }
}
