#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,ans,a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n>5000){
        int d=0x3f3f3f3f;
        for(int i=1;i<n;i++){
            d=min(d,abs(a[i+1]-a[i]));
        }
        m/=d;
        for(int i=1;i<=n;i++){
            if(m>=i){
                m-=i;
                ans++;
            }
            else break;
            if(m>=i){
                m-=i;
                ans++;
            }
            else break;
        }
        printf("%d",min(n,ans));
        return 0;
    }
    for(int i=1;i<=n;i++){
        int id=0;
        for(int j=1;j<=n;j++){
            if(a[i]-a[j]>=0)b[++id]=a[i]-a[j];
        }
        sort(b+1,b+id+1);
        int k=m,cnt=0;
        for(int j=1;j<=id;j++){
            if(b[j]<=k){
                k-=b[j];
                cnt++;
            }
            else break;
        }
        ans=max(ans,cnt);
    }
    printf("%d",ans);
    return 0;
}
