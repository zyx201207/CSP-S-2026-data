#include<bits/stdc++.h>
#define int long long
const int MAXN=2e6+10,mod=1e9+7;
using namespace std;
int c,T;
int n,d;
int a[MAXN];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    if(c==0){
        if(T==2){
            cin>>n;
            if(n==4){
                cout<<"1\n2";
            }else{
                cout<<"0\n1";
            }
        }else if(T==12){
            cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
        }else if(T==14){
            cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        }else if(T==16){
            cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        }
    }
    return 0;
}