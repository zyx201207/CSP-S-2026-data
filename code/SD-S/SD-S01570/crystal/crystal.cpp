#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010],c[500010];
long long m;
int best;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	bool flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i]-a[i-1];
	} 
	for(int i=3;i<=n;i++){
		if(c[i]!=c[i-1]){
			flag=1;
			break;
		} 
	}
	if(flag==0){
		long long sm,ans;
		for(int i=1;i<=n;i++){
			sm=i*(i-1)/2*c[2];
			if(m<sm){
				ans=i;
				break;
			}
		}
		cout<<ans-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long sum=0;
		int bigger=0;
		for(int j=1;j<=n;j++){
			s[j]=max(a[i]-a[j],(long long)0);
			sum+=s[j];
			if(a[j]>a[i]) bigger++; 
		}
		sort(s+1,s+1+n);
		int p=n;
		while(sum>m){
			sum-=s[p];
			p--;
			bigger++;
		}
		best=max(best,n-bigger);
	}
	cout<<best;
	return 0;
} 
