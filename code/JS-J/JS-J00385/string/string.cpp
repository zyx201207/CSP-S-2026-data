#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5;
char a[N];
ll b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>a[i];
        sum+=b[i];
    }
    ll ans=0;
    ll i=1,j=n;
    while(i<j){
        if(a[i]!=a[j]&&b[i]!=b[j]) ans+=min(abs(b[i]-b[j]),min(b[i],b[j]));
        else if(a[i]!=a[j]) ans+=b[i];
        if(b[i]>b[j]){
            b[i]-=b[j];
            j--;
        }else if(b[i]<b[j]){
            b[j]-=b[i];
            i++;
        }else{
            i++,j--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
