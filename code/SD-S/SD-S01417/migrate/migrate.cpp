//SQKS
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int C,T; 
int n;
ll m,c[2000010];
int d[5010][5010];
int tld[5010][5010];
bool vs[5010];
void dfs(int x,int cnt,int qx,int qy){
	if(x==qy){
		if(cnt<d[qx][qy])d[qx][qy]=cnt,tld[qx][qy]=1;
		else if(cnt==d[qx][qy])tld[qx][qy]++;
		return;
	}
	if(cnt>=d[qx][qy])return;
	for(int i=1;i<=n;i++){
		if(vs[i]||abs(c[i]-c[x])>m||i==x)continue;
		vs[i]=1;
		dfs(i,cnt+1,qx,qy);
		vs[i]=0;
	}
}
ll s[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>c[i];
		if(n<=9){
			int mg=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					d[i][j]=2e9;
					vs[i]=1;
					dfs(i,1,i,j);
					vs[i]=0;
					if(tld[i][j]==2)mg++;
				}
			}
			cout<<mg<<"\n";
			continue;
		}
		if(C>=13&&C<=14){
			int mg=0;
			for(int i=1;i<=n;i++){
				int tld=0;
				int j=i-1;
				while(j&&c[i]-c[j]<=m&&i-j<=2)j--;
				j++;
				tld+=i-j;
				j=i+1;
				while(j<=n&&c[j]-c[i]<=m&&j-i<=2)j++;
				j--;
				tld+=j-i;
				if(tld==2)mg++;
			}
			cout<<mg<<"\n";
			continue;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
