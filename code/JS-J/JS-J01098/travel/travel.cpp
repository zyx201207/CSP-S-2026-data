#include<bits/stdc++.h>
using namespace std;
const int N=0;
string c1,s1,c2,s2;
bool b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<char,bool> mp;
    mp['A']=0;
    mp['B']=0;
    mp['C']=0;
    mp['D']=1;
    mp['F']=1;
    cin>>c1>>s1>>c2>>s2;
    cout<<(b=(c1==c2));
    cout<<(b=b&&(s1[0]==s2[0])&&(s1[1]==s2[1]));
    cout<<(b=b&&(mp[s1[2]]==mp[s2[2]]));
    if(s1[2]=='F') s1[2]='E';
    if(s2[2]=='F') s2[2]='E';
    cout<<(b=b&&(abs(s1[2]-s2[2])==1));
    return 0;
}
