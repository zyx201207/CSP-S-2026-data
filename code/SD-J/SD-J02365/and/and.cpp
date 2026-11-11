#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5;
int n,m,a[N],g[40],k=1;
int f[N],s[N];
int maxx=INT_MIN;
int er(int c,int d){
	string s1="",s2="";
	int num=0;
	for(int i=29;i>=0;i--){
		if(c>=g[i]){
			c-=g[i];
			s1+='1';
		}
		else s1+='0';
		if(d>=g[i]){
			d-=g[i];
			s2+='1';
		}
		else s2+='0';
	}
	for(int i=0;i<30;i++){
		if(s1[i]=='1'&&s2[i]=='1') num+=g[29-i];
	}
	return num;
}
int dfs(int cnt){
	if(cnt==m){
		int num=a[s[1]];
		for(int i=1;i<=m;i++){
			num=er(num,a[s[i]]);
		}
		maxx=max(maxx,num);
	}
	for(int i=max(s[cnt],1ll);i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			s[cnt+1]=i;
			dfs(cnt+1);
			f[i]=0;
		}
	}
	return maxx;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	g[0]=1;
	for(int i=1;i<30;i++){
		k*=2;
		g[i]=k;
	}
	if(m==1) cout<<a[n];
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,er(a[i],a[j]));
			}
		}
		cout<<maxx;
	}
	else{
		cout<<dfs(0);	
	}
	return 0;
}
