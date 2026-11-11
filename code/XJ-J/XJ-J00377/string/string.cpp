#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans;
int a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1]){
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<' '<<c[i]<<'\n';
    // }
    int i=1,j=n;
    while(i<=j){
        // printf("%d %d %lld %lld %c %c\n",i,j,a[i],a[j],c[i],c[j]);
        if(c[i]==c[j]){
            if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }
            else if(a[i]==a[j]){
                i++,j--;
            }
            else{
                a[i]-=a[j];
                j--;
            }
        }
        else{
            if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }
            else if(a[i]==a[j]){
                ans+=a[i];
                i++,j--;
            }
            else{
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}