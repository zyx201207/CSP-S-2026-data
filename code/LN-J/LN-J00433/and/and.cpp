#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,w[101],v[N],h=0,s=0,f=1;
long long a[N],jz[101];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    long long cnt=n,ans=1;
    jz[0]=1;
    for(int i=1;i<=32;i++){jz[i]=jz[i-1]*2;ans+=jz[i];}
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;jz[j]<=a[i];j++){
            if((1&(a[i]>>j))==1){
                w[j]++;
                h=max(h,j);
            }
        }
    }
    for(int i=h;i>=0;i--){
        if(w[i]>=m){
            s=i;
            break;
        }
    }
    for(int i=s;i>=0&&f;i--){
        if(w[i]<m)continue;
        for(int j=1;j<=n&&f;j++){
            if(v[j]==1)continue;
            if((1&(a[j]>>i))!=1){
                v[j]=1;
                cnt--;
                if(cnt==m){
                    f=0;
                    break;
                }
                for(int k=0;jz[k]<=a[j];k++){
                    if((1&(a[j]>>k))==1)w[k]--;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]==0)ans&=a[i];
    }
    cout<<ans;
    return 0;
}
