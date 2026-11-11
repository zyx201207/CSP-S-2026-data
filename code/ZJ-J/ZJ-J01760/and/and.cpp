#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],mx,t,f[35],m,k;
bool v[200005][35];
bool dfs(int k,int p){
	int l=0;
	memset(f,0,sizeof(f));
	for(int j=1;j<=n;j++){
		if(v[j][k]==1){
			l++;
			for(int i=0;i<=31;i++)f[i]+=v[j][i];
		}
	}
	if(l<m)return 0;
	for(int i=k-1;i>=0;i--){
		if(f[i]>=m){
			if(!dfs(i,p+pow(2,i))){
				cout<<p;
			}return 1;
		}
	}cout<<p;return 1;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];t=a[i];
		for(int j=31;j>=0;j--){
			if(t>pow(2,j)){
				t-=pow(2,j);
				v[i][j]=1;
				f[j]++;
			}
		}
	}
	for(int i=31;i>=0;i--){
		if(f[i]>=m){
			k=i;
			break;
		}
	}
	dfs(k,pow(2,k));
	return 0;
}