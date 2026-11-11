#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int N=2e5+7;
int a,b;
string x,y;
map<char,bool> mp;
void mian(){
    mp['A']=mp['B']=mp['C']=1;
    mp['D']=mp['F']=0;
    cin>>a>>x>>b>>y;
    if(a==b){
        cout<<1;
        if(x.substr(0,2)==y.substr(0,2)){
            cout<<1;
            if(mp[x[2]]==mp[y[2]])
                cout<<1<<(abs(x[2]-y[2])==1)?1:0;
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return ;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int _77231=1;
    // cin>>_77231;
    while(_77231--)mian();
}