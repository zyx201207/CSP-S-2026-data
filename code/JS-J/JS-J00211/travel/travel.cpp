#include<bits/stdc++.h>
using namespace std;
#define int long long
ifstream fin("travel.in");
ofstream fout("travel.out");
#define cin fin
#define cout fout
string c1,c2,s1,s2;
bool res[4];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) for(int i=0;i<4;++i) res[i]=0;
    else{
        res[0]=1;
        if(s1[0]!=s2[0]||s1[1]!=s2[1]) for(int i=1;i<4;++i) res[i]=0;
        else{
            res[1]=1;
            if(!(s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'||s2[2]>='D')) for(int i=2;i<4;++i) res[i]=0;
            else{
                res[2]=1;
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) res[3]=1;
                else res[3]=0;
            }
        }
    }
    for(int i=0;i<4;++i) cout<<res[i];
    return 0;
}
