#include<bits/stdc++.h>
using namespace std;
int n,m,ans,op,a[200010],f[200010][2];
bool b[200010][2];
vector<int> v[40];
void dfs(int c,int k,int now){
	if(k>=m){
		ans=max(ans,now);
		return;
	}
	if(c>n)
		return;
	dfs(c+1,k,now);
	dfs(c+1,k+1,now&a[c]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20){
		//25`(5/20)
		dfs(1,0,INT_MAX);
		cout<<ans;
	}
	else if(n<=2000&&m<=2){
		//20`(4/20)
		f[0][0]=INT_MAX;
		for(int j=1;j<=m;j++){
			op^=1;
			for(int i=0;i<=n;i++)
				f[i][op]=0;
			for(int i=1;i<=n;i++)
				for(int k=0;k<i;k++)
					f[i][op]=max(f[i][op],f[k][op^1]&a[i]);
		}
		for(int i=1;i<=n;i++)
			ans=max(ans,f[i][op]);
		cout<<ans;
	}
	else{
		//55`(11/20)
		for(int i=30;i>=0;i--){
			op^=1;
			for(int j=1;j<=n;j++)
				b[j][op]=false;
			for(int j=1;j<=n;j++)
				if(((a[j]>>i)&1)&&!b[j][op^1])
					v[i].push_back(j);
				else
					b[j][op]=true;
			if(v[i].size()>=m)
				ans+=(1<<i);
			else
				op^=1;
		}
		cout<<ans;
	}
	return 0;
}
