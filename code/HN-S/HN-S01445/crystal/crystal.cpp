#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		if(a[i]==a[i+1])ans++;
	}
	bool f=1;
	for(long long i=1;i<=n-1;i++){
		b[i]=abs(a[i]-a[i+1]);
		if(b[i]<m)f=0;
	}
	
	if(f){
		cout<<0;
		return 0;
	}
	long long h;
	for(long long i=1;i<=n-1;i++){
		sum=0;
		long long t=1;
		h=i;
		while(1){
			if(sum>=m||h>=n)break;
			sum+=b[h]*t;
			t++;
			h++;
			//cout<<"@"<<sum<<endl;
		}
		if(sum>m)t--;
		ans=max(t,ans);
	}
	cout<<ans;
	return 0;
}
