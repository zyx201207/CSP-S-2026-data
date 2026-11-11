#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre[500005],b,ans1,ans,ans2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);pre[0]=0;
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(long long i=1,j=1;i<=n,j<=n;j++){
		ans1=(j-i)*a[j]-pre[j-1]+pre[i-1];ans++;
		while(ans1>m){
			i++;ans1=(j-i)*a[j]-pre[j-1]+pre[i-1];ans--;
		}
		ans2=max(ans2,ans);
//		(pre[i+b]-pre[i])-(pre[i-1]-pre[i-b-1])+pre[n]-pre[i+b]-(n-i-b)*a[i]
//		(pre[i+b]-pre[i])-(pre[i-1]-pre[i-b-1])+(i-b-1)*a[i]-pre[i-b-1]
	}
//	for(int i=1;i<=n;i++){
//		c[i]=a[f]-a[i];
////		cout<<c[i]<<' ';
//	}
//	sort(c+1,c+n+1,cmp);ans=0;
//	for(long long i=1;m>0;i++){
//		if(i>n||c[i]<0) break;
//		if(m>=c[i]){
//			m-=c[i];ans++;
//		}
//		else if(c[i]>m)
//		break;
//	}
	cout<<ans2;
	return 0;
}
