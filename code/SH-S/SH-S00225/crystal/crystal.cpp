#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+335,maxm=5e3+33;
long long n,m,a[maxn],tmp=0,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if (n>=5000){
		for (int i=2;i<=n;i++){
			tmp+=(a[i]-a[i-1])*(i-1);
			if (tmp>m) break;
			ans++;
		}	
	}else{
		for (int i=1;i<=n;i++){
			long long sum=0;
			tmp=0;
			for (int j=max(2,i+1);j<=n;j++){
				tmp+=(a[i]-a[i-1])*(i-1);
				if (tmp>m) break;
				sum++;
			}
			ans=max(sum,ans);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
