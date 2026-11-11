#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	int a[n+10]{},aaa=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		aaa=max(aaa,abs(a[i]));
	}
	sort(a+1,a+n+1);
	if(n<=5100){
		int ans=0;
		for(int i=1;i<=n;i++){
			int s1=0,s2=0;
			for(int j=i;j>0;j--){
				if(s1+a[i]-a[j]<=m&&(!(s1+a[i]-a[j]<0))){
					s1+=a[i]-a[j];
					s2++;
				}
				else{
					break;
				}
			}
			ans=max(ans,s2);
		}
		printf("%lld",ans);
		return 0;
	}
	if(aaa<=200){
		int ans=0;
		for(int i=-aaa;i<=aaa;i++){
			int s1=0,s2=0;
			for(int j=1;j<=n;j++){
				if(a[j]>i){
					break;
				}
				if(s1+i-a[j]<=m){
					s1+=i-a[j];
					s2++;
				}
				else{
					break;
				}
			}
			ans=max(ans,s2);
		}
		printf("%lld",ans);
		return 0;
	}
	int ss=a[2]-a[1];
	int ans=0;
	for(int i=1;i<n;i++){
		if(ans+ss*i>m||(ans+ss*i<0)){
			printf("%lld",i);
			break;
			return 0;
		}
		ans+=ss*i;
	}
	printf("%lld",n);
//	int b[n+10]{};
//	int ans=1;
//	queue <int> q;
//	q.push(1);
//	int s1=1;
//	for(int i=2;i<=n;i++){
//		if(a[i]==a[i-1]) b[i]=b[i-1];
//		else b[i]=a[i]-a[i-1]+b[i-1]*(i-1);
//		while(!q.empty()&&b[i]-(a[i]-a[q.front()-1])*(q.front()-1)-b[q.front()]>m){
//			q.pop();
//			s1--;
//		}
//		s1++;
//		q.push(i);
//		ans=max(ans,s1);
//	}
//	printf("%lld",ans);
	return 0;
}
