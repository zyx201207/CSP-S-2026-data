#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,k;
long long a[500010],s[500010],b[500010];
bool f=1,fl=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int c=a[2]-a[1];
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]!=1) f=0;
        if(a[i+1]-a[i]!=c){
            fl=0;
            break;
        }
    }
    if(fl==1){
        long long i=1;
        while(i){
            ans=ans+i*c;
            if(ans>m){
                break;
            }
            i++;
        }
        cout<<i<<endl;
        return 0;
    }
    if(n<=5000){
        for(int i=1;i<n;i++){
            s[i]=i*(a[i+1]-a[i]);
        }
        for(int i=1;i<n;i++) b[i]=b[i-1]+s[i];
        for(int i=1;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            k=j-i+2;
            if(b[j]-b[i-1]>m) continue;
            ans=max(ans,k);
        }
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}
