#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,q,s;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>q;
    while(q--){
        s=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(max(a[i],a[j])-min(a[j],a[i])<=d){
                    s++;
                }
            }
        }
        cout<<s/2<<endl;
    }
    return 0;
}
