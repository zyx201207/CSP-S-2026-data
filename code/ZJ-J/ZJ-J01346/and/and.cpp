#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int d[32][200100];
int nd[200100];
int nnd[200100];
int x;
int cnt=n;
int res[101];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>x;
		int sum=-1;
		while(x>0){
			d[++sum][i]=x%2;
			x/=2;
		}
	}
	for(int i=1;i<=n;i++){
		nd[i]=i;
	}
	for(int k=29;k>=0;k--){
		int sum=0;
		for(int i=1;i<=cnt;i++){
			if(d[k][nd[i]]==1)sum++;
		}
		if(sum>=m){
			res[k]=1;
			sum=0;
			for(int i=1;i<=cnt;i++){
				if(d[k][nd[i]]==0)continue;
				++sum;
				nnd[sum]=nd[i];
			}
			cnt=sum;
			for(int i=1;i<=cnt;i++){
				nd[i]=nnd[i];
			}
		}
	}
	int ans=0;
	for(int i=29;i>=0;i--){
		ans+=res[i]*(1<<i);
	}
	cout<<ans;
	return 0;
}
