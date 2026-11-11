#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll maxx,s;
ll a[200005],a1[200005];
char b[200005],b1[200005];
string c,d;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    cin>>n;
   for(ll i=1;i<=n;i++){
        cin>>a[i];
        a1[n-i+1]=a[i];
        cin>>b[i];
        b1[n-i+1]=b[i];
        maxx=max(maxx,a[i]);
   }
    if(maxx<=500){
        for(ll i=1;i<=n;i++){
         for(ll j=1;j<=a[i];j++){
               c+=b[i];
            }
        }
        for(ll i=n;i>=1;i--){
            for(ll j=1;j<=a[i];j++){
                d+=b[i];
            }
        }
        for(ll i=0;i<c.size();i++){
           if(c[i]!=d[i]){
                s++;
            }
        }
        s/=2;
        cout<<s;
        return 0;
    }
    for(ll i=1;i<=n;){
        for(ll j=1;j<=n;){
            if(b[i]=b1[j]){
                if(a[i]<=a1[j]){
                    i++;
                    a1[j]-=a[i];
                }else{
                    j++;
                    a[i]-=a1[j];
                }
            }else{
                if(a[i]<=a1[j]){
                    i++;
                    s+=a[i];
                    a1[j]-=a[i];
                }else{
                    j++;
                    s+=a1[j];
                    a[i]-=a1[j];
                }
            }
        }
    }
    s/=2;
    cout<<s;
    return 0;
}
