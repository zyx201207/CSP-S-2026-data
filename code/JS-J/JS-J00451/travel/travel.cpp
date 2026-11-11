#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const int inf=0x3f3f3f3f;
const double eps=1e-9;
using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string ans="0000";
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans[0]='1';
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            ans[1]='1';
            if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')){
                ans[2]='1';
                if(abs((int)s1[2]-(int)s2[2])==1) ans[3]='1';
            }
        }
    }
    cout<<ans;
    //08:37



    return 0;
}
