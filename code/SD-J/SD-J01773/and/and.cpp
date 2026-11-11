#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
int n,m,a[N];
int sum,b[N],mx=-1e9;
int cnt[N];
bool v[N];
void dfs(int x){
	if(x>m){
		int sum=b[1];
		for(int i=2;i<=m;i+=1){
			sum&=b[i];
//			cout<<b[i]<<" ";
		}
//		cout<<endl;
//		cout<<sum<<endl;
		mx=max(mx,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			b[x]=a[i];
			v[i]=1;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<mx;
	return 0;
}
