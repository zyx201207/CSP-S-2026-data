#include<bits/stdc++.h>
using namespace std;
int a[500010];
int cha[500010];
int pre[500010];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)  cha[i-1]=a[i]-a[i-1];
    for(int i=1;i<n;i++)  pre[i]=pre[i-1]+cha[i];
    for(int i=1;i<n;i++){
        int l=i,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(pre[mid]-pre[i-1]>m){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,l-i+1);
    }
    cout<<ans;
    return 0;
}
