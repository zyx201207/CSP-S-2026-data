#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,id;
int ch[N*31][2];
int cnt[N];
void Insert(int x){
	int u=0;
	for(int i=30;i>=0;i--){
		int c=((x>>i)&1);
		if(!ch[u][c]) ch[u][c]=++id;
		u=ch[u][c];
		cnt[u]++;
	}
}
void Merge(int u,int v){
	cnt[u]+=cnt[v];
	if(ch[u][1]&&ch[v][1])
		Merge(ch[u][1],ch[v][1]);
	else if(!ch[u][1]&&ch[v][1])
		ch[u][1]=ch[v][1];
	if(ch[u][0]&&ch[v][0])
		Merge(ch[u][0],ch[v][0]);
	else if(!ch[u][0]&&ch[v][0])
		ch[u][0]=ch[v][0];
} 
int Query(){
	int u=0,res=0;
	for(int i=30;i>=0;i--){
		if(!ch[u][1]){
			u=ch[u][0];
			continue;
		}
		if(ch[u][1]&&cnt[ch[u][1]]>=m){
			res+=(1<<i);
			u=ch[u][1];
		}else{
			Merge(ch[u][0],ch[u][1]);
			u=ch[u][0];
		} 
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("and5.in","r",stdin);
//	freopen("and5.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		Insert(x);
	}
	cout<<Query();
    return 0;
}
