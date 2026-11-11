#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e5+10;
long long a[N],b[M],q[N];
char c[N],d[M];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,f,h=0;
    cin>>n;
    int x=n;
    int cnt;
    int ok=0;
    long long u=0;
    if(x%2==0){
        f=x/2;
        cnt=f+1;
    }else{
        f=(x-1)/2;
        cnt=f+2;
        ok=1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        u+=a[i];
    }

    int cn=0;
    for(int i=2;i<=n;i++){
        cn+=a[i];
        if(cn<=f){
            if(a[i]==a[i-1]){
                b[cnt]+=a[i];
                d[cnt]=c[i];
            }else{
                q[cnt]+=b[cnt];
                cnt++;
            }
        }else{
            b[cnt]=cn-q[cnt];
        }
    }
    long long ans=0;
    if(ok=0){
        for(int i=f+1;i<=n;i++){
            if(c[i]!=d[i]){
                ans=ans+abs(b[i]-a[i]);
            }
        }
    }else{
        for(int i=f+2;i<=n;i++){
            if(c[i]!=d[i]){
                ans=ans+abs(b[i]-a[i]);
            }
        }
    }
    cout<<ans;
    return 0;
}
