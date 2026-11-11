#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("travel.in");
    ofstream fout("travel.out");
    int a,b,e,f;
    char c,d;
    fin>>a>>e>>c;
    fin>>b>>f>>d;
    if(a==b)fout<<1;
    else fout<<0;
    if(a==b&&e==f)fout<<1;
    else fout<<0;
    if(a==b&&e==f&&(c<='C'&&d<='C')||(c=='D'||c=='F')&&(d=='D'||d=='F'))fout<<1;
    else fout<<0;
    if(a==b&&e==f&&(c<='C'&&d<='C')||(c=='D'||c=='F')&&(d=='D'||d=='F')&&(c-d==1||d-c==1))fout<<1;
    else fout<<0;
    return 0;
}
