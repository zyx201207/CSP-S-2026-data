#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<'1';
            bool ce1,ce2;
            ce1='A'<=s1[2]&&s1[2]<='C';
            ce2='A'<=s2[2]&&s2[2]<='C';
            if(ce1==ce2){
                cout<<'1';
                if(!ce1||abs(s1[2]-s2[2])==1){
                    cout<<'1';
                }else{
                    cout<<'0';
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
}

signed main(){
    clock_t st=clock();

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cerr.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<"耗时:"<<(double)(clock()-st)*1000/CLOCKS_PER_SEC<<"ms";
}
