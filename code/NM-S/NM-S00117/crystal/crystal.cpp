#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
        long long s=0,sum=1;
        for(int j=i-1;j>=1;j--){
            long long y=a[i]-a[j];
            if(s+y<=m){
                s+=y;
                sum++;
            }
            else break;
        }
        ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
