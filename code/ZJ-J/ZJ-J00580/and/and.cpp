#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,n,m,a[200010],fl2[200010],j,fl[200010];
vector<int>f[40];
void dfs(int t,int s,int c){
	if(c==m){
		s=0;
		for(i=1;i<=n;i++)
			if(fl[i]==0)
				if(s==0)s=a[i];
				else s&=a[i];
		cout<<s;
		exit(0);
	}
	if(t==-1){
		cout<<s;
		exit(0);
	}
	int ans=0;
	for(i=1;i<=n;i++)fl2[i]=1;
	if(f[t].size()<m)dfs(t-1,s,c);
	else{
		for(i=0;i<f[t].size();i++)
			if(fl[f[t][i]]==0)ans++;
		if(ans<m)dfs(t-1,s,c);
		else{
			c=0;
			for(i=0;i<f[t].size();i++)
				if(fl[f[t][i]]==0)
					fl2[f[t][i]]=0,c++;
			for(i=1;i<=n;i++)
				if(fl2[i])fl[i]=1;
			dfs(t-1,s+pow(2,t),c);
		}
	}
	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		for(j=0;j<=30;j++)
			if(a[i]&(1<<j))f[j].push_back(i);
	}
	dfs(30,0,n);
	
	return 0;
}
