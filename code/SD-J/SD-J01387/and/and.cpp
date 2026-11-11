#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
long long a[N];
bool flag=true;
map<long long,bool> p;
void init(){
	for(int i=0;i<=30;++i){
		p[pow(2,i)-1]=true;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(p[a[i]]==false)flag=false;
	}
	if(flag){
		sort(a+1,a+1+n,greater<int>());
		long long ans=a[1];
		for(int i=2;i<=m;++i)ans&=a[i];
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		long long maxn=INT_MIN;
		for(int i=1;i<=n;++i)maxn=max(maxn,a[i]);
		cout<<maxn<<'\n';
		return 0;
	}
	if(m==2){
		long long maxn=INT_MIN;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j)maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn<<'\n';
		return 0;
	}
	if(n==m){
		long long ans=a[1];
		for(int i=2;i<=n;++i)ans&=a[i];
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n-1){
		long long maxn=INT_MIN;
		long long res=a[1];
		for(int i=2;i<=n;++i)res&=a[i];
		for(int i=1;i<=n;++i)maxn=max(maxn,res&(a[i]-1));
		cout<<maxn<<'\n';
		return 0;
	}
	long long maxn=INT_MIN;
	long long ans=0,cnt=0;
	for(int i=1;i<=n;++i){
		ans=a[i];
		cnt=0;
		cnt++;
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			ans&=a[j];
			cnt++;
			if(cnt==m){
				maxn=max(maxn,ans);
				break;
			}
			for(int k=1;k<=n;++k){
				if(j==k)continue;
				ans&=a[j];
				cnt++;
				if(cnt==m){
					maxn=max(maxn,ans);
					break;
				}
			}
		}
	}
	cout<<maxn<<'\n';
	return 0;
}

