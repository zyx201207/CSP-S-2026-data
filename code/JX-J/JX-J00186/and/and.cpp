#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool f[200005][30];
bool b[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		b[i]=1;
		cin>>a[i];
		for(int j=0;j<30;j++){
			if(a[i]&(1<<j))f[i][j]=1;
		}
	}
	int ans=0;
	for(int j=29;j>=0;j--){
		int num=0;
		for(int i=1;i<=n;i++){
			if(f[i][j]&&b[i])num++;
		}
		if(num>=m){
			ans|=(1<<j);
			for(int i=1;i<=n;i++){
				if(f[i][j]==0)b[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
