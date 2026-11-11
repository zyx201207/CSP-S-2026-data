/*
shu ju fan wei xia ku le TVT
CCF bu yao zhe yang dui wo...
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
int n;
long long s,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    for(int i=1;i<=n/2;i++){
        if(a[i]==a[n-i+1]&&c[i]!=c[n-i+1]) ans+=a[i];
        if(a[i]!=a[n-i+1]){
            if(a[i]>a[n-i+1]){
                if(c[i]==c[n-i+1]){
                    if(c[i]!=c[n-i]){
                        ans+=a[i]-a[n-i+1];
                        a[n-i]=a[n-i]-(a[i]-a[n-i+1]);
                    }
                }
                else{
                    if(c[i]!=c[n-i]){
                        ans+=a[i];
                        a[n-i]=a[n-i]-(a[i]-a[n-i+1]);
                    }
                    else ans+=a[n-i+1];
                }
            }
            else{
                if(c[i+1]==c[n-i+1]){
                    if(c[i+1]!=c[n-i+1]){
                        ans+=a[n-i+1]-a[i];
                        a[i+1]=a[i+1]-(a[n-i+1]-a[i]);
                    }
                }
                else{
                    if(c[i]!=c[n-i]){
                        ans+=a[n-i+1];
                        a[i+1]=a[i+1]-(a[n-i+1]-a[i]);
                    }
                    else ans+=a[i];
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}