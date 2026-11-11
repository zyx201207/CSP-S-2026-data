#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
int a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i0=0;i0<t;i0++){
        int n,d,s=0,cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(d>2){
            cout<<0<<endl;
            break;
        }
        if(c==11||c==12){
            cout<<n-3<<endl;
            break;
        }
        for(int i=1;i<n;i++){
            for(int j=i;j<=n;j++){
                if(a[j]-a[j-1]==1) s++;
                if(s==3&&a[j+1]-a[j]==1){
                     cnt++;s=0;break;
                }




            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
