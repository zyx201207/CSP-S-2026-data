#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[100005],maxn=0,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int p=(1<<30);
	for(int tp=30;tp>=0;tp--){
		int cnt=0;
		for(int i=1;i<=n;i++){	
			if(a[i]>=p&&f[i]==0){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++)if(!(a[i]>=p&&f[i]==0))f[i]=1;
			for(int i=1;i<=n;i++)if(a[i]>=p&&f[i]==0)a[i]-=p;
			ans+=p;
		}
		p/=2;
		
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12


5 3
31 3 1 15 7


*/














