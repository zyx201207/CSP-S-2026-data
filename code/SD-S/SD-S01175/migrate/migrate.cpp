#include<bits/stdc++.h>
using namespace std;
long long a[2000005],f[2000005],c[2000005];
int pr[2000005];
long long cnt[2000005];
int ccc,t;
void work(){
	int n;
	long long d;
	cin>>n>>d;
	int l=1;
	for(int i=1;i<=n;i++)f[i]=c[i]=pr[i]=cnt[i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(l<i&&a[i]-a[l]>d)l++;
		pr[i]=l;
		cnt[pr[i]]++;
	}
	if(n==1){
		cout<<"0\n";
		return;
	}
	if(ccc<=10){
		long long ans=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
			c[i]=1;
			for(int j=i+1;j<=n;j++){
				int x=max(i,pr[j]);
				f[j]=f[x]+1;
				c[j]=c[x];
				if(x+1<j&&f[x+1]==f[x])c[j]+=c[x+1];
				if(x+2<j&&f[x+2]==f[x])c[j]+=c[x+2];
				if(c[j]>3)c[j]=3;
				ans+=(c[j]==2);
			}
		}
		cout<<ans<<"\n";
	}else if(c<=12){
		long long p=d/(a[2]-a[1]);
		if(p<=1)cout<<"0\n";
		else cout<<max(0ll,n-2*p+1)<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ccc>>t;
	while(t--)work();
	return 0;
}

