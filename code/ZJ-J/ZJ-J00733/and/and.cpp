#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
#define N 200005
using namespace std;//65pts
int n,m;
int a[N];
int ans;
bitset<N>vis;
int k[N][35];
vector<int>G[35];
void dfs(int d,int sum){
	if(d==m+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(d+1,sum&a[i]);
		vis[i]=0;
	}
}
bool kill1(){//25pts
	if(m>20)return 0;
	dfs(1,2147483647);
	printf("%d",ans);
	return 1;
}
bool kill2(){//5pts
	if(m!=1)return 0;
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans=max(ans,a[i]);
	}
	printf("%d",ans);
	return 1;
}
bool kill3(){//5pts
	if(m!=n)return 0;
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	printf("%d",ans);
	return 1;
}
bool kill4(){//15pts
	if(m!=2||n>2000)return 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	printf("%d",ans);
	return 1;
}
bool kill5(){//10pts
	if(a[n]>=4)return 0;
	printf("%d",a[n-m+1]);
	return 1;
}
/*
15 7
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		int x=a[i],cnt=0;
		while(x){
			if(x&1)k[i][cnt]=1,G[cnt].eb(i);
			x>>=1;
			cnt++;
		}
	}
	sort(a+1,a+n+1);
	if(kill1())return;
	if(kill2())return;
	if(kill3())return;
	if(kill4())return;
	if(kill5())return;
	for(int i=0;i<30;i++){//die  >=5pts
		if((int)G[i].size()>=m)ans|=(1<<i);
	}
	printf("%d",ans);
}
/*
11111
11000
10000
11110
11100
*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
