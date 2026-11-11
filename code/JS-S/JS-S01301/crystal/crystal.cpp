#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,N1=5010;
long long n,m,a[N],b[N],c[N],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int f=1;
    int f1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            f=0;
        }
        if(i>=2){
            if(a[i]-a[i-1]!=a[2]-a[1]){
                f1=0;
            }
        }
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(long long i=n;i>=1;i--){
            for(long long j=i;j>=1;j--){
                b[j]=a[i]-a[j];
            }
            c[i]=b[i];
            for(long long j=i-1;j>=1;j--){
                c[j]=c[j+1]+b[j];
            }
            for(long long j=1;j<=i;j++){
                if(c[j]<=m){
                    ans=max(ans,i-j+1);
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(f==1){
        long long l=0;
        for(int i=1;i<=n;i++){
            if(l<=m){
                ans++;
            }
            else{
                break;
            }
            l+=i;
        }
        cout<<ans;
        return 0;
    }
    if(f1==1){
        long long l=0;
        for(int i=1;i<=n;i++){
            if(l<=m){
                ans++;
            }
            else{
                break;
            }
            l+=(i*(a[2]-a[1]));
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
