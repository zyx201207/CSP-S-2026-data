#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++)if(a[j]&(1<<i))cnt++;
        if(cnt>=m)ans+=(1<<i);
        if(cnt>=m)for(int j=1;j<=n;j++)if(!(a[j]&(1<<i)))a[j]=0;
    }
    printf("%d",ans);
}
