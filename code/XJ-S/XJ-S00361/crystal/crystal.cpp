#include<bits/stdc++.h>
using namespace std;

const int N=50010;
int a[N],ans;
long long s[N][N];
int n;
long long m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int t=a[i+1]-a[i];
		if(a[i]!=a[i+1]){
			for(int j=1;j<=t;j++){
				if(s[i][j]<=m){
					s[i][j]=max(s[i-1][j],s[i-1][j-t]+1);
				}
				a[i]++;
				if(a[i]==a[i+1]) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
