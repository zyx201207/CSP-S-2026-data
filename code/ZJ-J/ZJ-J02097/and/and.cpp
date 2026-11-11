#include <bits/stdc++.h>
using namespace std;
bool b[200005][35];
vector <int> v[35];
int a[200005];
long long ans=0;
long long f(int x){
	long long r=1;
	for(int i=1;i<x;i++)
		r*=2;
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int l=0,x=a[i];
		while(x){
			b[i][++l]=x%2;
			x/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			cout<<b[i][j]<<' ';
		}
		cout<<'\n';
	}
	for(int i=1;i<=n;i++)
		v[1].push_back(i);
	for(int i=31;i>=1;i--){
		int t=0;
		for(int j=0;j<v[31-i+1].size();j++){
			if(b[v[31-i+1][j]][i])
			    t++;
		}
			
		if(t>=m){
			for(int j=0;j<v[31-i+1].size();j++){
				if(b[v[31-i+1][j]][i])
				    v[31-i+2].push_back(v[31-i+1][j]);
			}
			ans+=f(i);
		}
		else{
			for(int j=0;j<v[31-i+1].size();j++){
				v[31-i+2].push_back(v[31-i+1][j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
