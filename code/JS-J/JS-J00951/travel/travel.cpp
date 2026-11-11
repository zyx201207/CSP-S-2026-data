#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
map<char,int> m;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    m['A']=m['B']=m['C']=0,m['D']=m['F']=1;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            if(m[s1[2]]==m[s2[2]]){
                cout<<1;
                int x=(int)(s1[2]-'0'),y=(int)(s2[2]-'0');
                cout<<(abs(x-y)==1?1:0)<<'\n';
            }else cout<<"00\n";
        }else cout<<"000\n";
    }else cout<<"0000\n";
    return 0;
}