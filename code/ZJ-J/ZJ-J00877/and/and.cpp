#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
long long n,m,ans;
long long a[200010];
bool f[35][200010],f1[35][200010];
int main(){
	fast;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		for(int j=0;j<=31;j++){
			if((x>>j)&1){
				f[j][i]=true;
			}
		}
	}
	for(int i=31;i>=0;i--){
		long long x=0;
		for(int j=1;j<=n;j++){
			if(f1[i][j]==false){
				if(f[i][j]==true){
					x++;
				}
				else{
					f1[i][j]=true;
				}
			}
		}
		if(x>=m){
			ans+=(long long)(1<<i);
		}
		else{
			for(int j=1;j<=n;j++){
				f1[i][j]=f1[i+1][j];
			}
		}
		if(i!=0){
			for(int j=1;j<=n;j++){
				f1[i-1][j]=f1[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}
