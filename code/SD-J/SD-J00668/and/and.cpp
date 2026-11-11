#include<bits/stdc++.h>
using namespace std;
bool a[50][200010];
bool b[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		long long x;
		cin>>x;
		int cnt=39;
		while(x){
			a[cnt][i]=x%2;
			x/=2;
			cnt--;
		}
	}
	for(int i=1;i<=39;++i){
		int num=0;
		for(int j=1;j<=n;++j){
			if(a[i][j]==1 && b[j]!=1)++num;
		}
		if(num>=m){
			ans+=pow(2,39-i);
			for(int j=1;j<=n;++j){
				if(b[j]!=1){
					if(a[i][j]==0)b[j]=1;
				}
			}
		}
	}
	cout<<ans;
}
