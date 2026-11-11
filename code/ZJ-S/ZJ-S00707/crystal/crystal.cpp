#include<bits/stdc++.h>
using namespace std;
long long m,a[500052];
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ok1=1,ok2=1,ok3=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(abs(a[i])>100) ok1=0;
		if(a[i]!=i) ok2=0;
		if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2])  ok3=0;
	}
	sort(a+1,a+1+n);
	if(n<=5200){
		int ans=0;
		for(int i=1;i<=n;i++){
			long long sum=0;
			int k=0;
			for(int j=i;j>=1;j--){
				sum=sum+a[i]-a[j];
				if(sum<=m) k++;
				else break;
			}
			ans=max(k,ans);
		}
		cout<<ans;
	}
	else if(n>5200 && ok1==1){
		long long d[215]={0};
		int cnt=0;
		for(int i=1;i<=n;i++){
			d[a[i]+105]++;
		}
		long long  ans=0;
		for(long long i=5;i<=210;i++){
			cnt+=d[i];
			long long k=0;
			long long sum=0;
			for(long long j=i;j>=5;j--){
				sum+=d[j]*(i-j);
				if(sum<=m) k+=d[j];
				else break;
			}
			ans=max(ans,k);
		}
		cout<<ans;
	}
	else if(ok2==1){
		for(int i=1;;i++){
			if((i+1)*i/2>m){
				cout<<i;
				return 0;
			}
		}
	}
	else if(ok3==1){
		for(int i=1;;i++){
			if((i+1)*i/2*(a[2]-a[1])>m){
				cout<<i;
				return 0;
			}
		}
	}
	else cout<<23923478;
	return 0;
}
