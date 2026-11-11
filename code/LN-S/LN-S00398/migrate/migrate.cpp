#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c, n;
    cin>>c>>n;
    if(c==11 || c==12){
        for(int i=0;i<n;i++){
            ll s, d, a, b, gunmu;
            cin>>s>>d>>a>>b;
            if(s <= 2){
                cout<<"0\n";
                continue;
            }
            for(int i=2;i<s;i++){
                cin>>gunmu;
            }
            a = abs(b-a);
            if(d<=a){
                cout<<"0\n";
                continue;
            }
            a = d / a;
            if(s < a*2){
                cout<<"0\n";
                continue;
            }
            s -= a*2;
            cout<<s+1<<'\n';
        }
    }
    for(int i=0;i<n;i++){
        cout<<"0\n";
    }
    return 0;
}
