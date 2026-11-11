#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char b[200010];
long long m;
long long cnt;
bool q;
long long x;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        m=m+a[i]/2;
    }
    for(long long i=1;i<=n;i++){
        cnt+=a[i];
        if(cnt>=m){
            q=(cnt==m);
            cnt=i;
            break;
        }
    }
    for(long long i=1,k=n;i<=cnt;i++){
        if(i==cnt){
            if(!q){
                x=0;
                for(long long j=i+1;j<=k;j++){
                    if(a[j]!=0){
                        if(b[j]!=b[i]){
                           x+=a[j];
                        }
                    }
                    else{
                        break;
                    }
                }
                ans+=x;
                break;
            }
        }
        for(;k>=cnt;k--){
            if(a[i]>a[k]){
                a[i]-=a[k];
                if(b[i]!=b[k]){
                    ans+=a[k];
                }
                a[k]=0;
                continue;
            }
            if(a[i]<a[k]){
                a[k]-=a[i];
                if(b[i]!=b[k]){
                    ans+=a[i];
                }
                a[i]=0;
                break;
            }
            if(a[i]==a[k]){
                if(b[i]!=b[k]){
                    ans+=a[i];
                }
                a[i]=a[k]=0;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
