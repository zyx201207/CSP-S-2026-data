#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
#define N 500005
#define M 300005
using namespace std;//88-100pts
int n,m;
int a[N];
int nxt[N];
int pos[M];
int cnt[M];//int
bitset<N>ok;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(pos[a[i]])nxt[pos[a[i]]]=i;
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!nxt[i])nxt[i]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		do{
			if(nxt[j]==j)cnt[a[j]]++,j=j+1;
			else j=nxt[j];
		}while(j<=n);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
