#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;
ll m,a[N],s[N];
int res;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,ans=r;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)r=(ans=mid)-1;
            else l=mid+1;
        }
        res=max(res,i-ans+1);
    }
    printf("%d\n",res);
    return 0;
}