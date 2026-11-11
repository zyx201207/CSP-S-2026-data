#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[500005],b=1,c=0,ans=1;
map<ll,ll> ma;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

        ma[a[i]]++;
    }
    sort(a+1,a+n+1);
    c=a[1];
    while(b<n){
        if(a[b+1]==c){
            b++;
            ans++;
        }else{
            if(m>=(a[b+1]-c)*b){
                //cout<<ans<<' '<<m<<' '<<c<<' '<<b<<endl;

                m-=(a[b+1]-c)*b;
                c=a[b+1];
                b+=ma[a[b+1]];
                ans+=ma[a[b]];

            }else{
                //cout<<ans<<' '<<m<<' '<<c<<' '<<b<<endl;
                cout<<ans;
                return 0;
            }
        }


    }



    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
