#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q,ti[M],kth[M];
int num,ne[M],wi[M],head[M],to[M];
void add(int u,int v,int w){
	ne[num]=head[u];
	to[num]=v;
	wi[num]=w;
	head[u]=num++;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ti[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		kth[i]+=k;
		int a,t,last_a;
		cin>>a>>t;
		last_a=a;
		for(int j=2;j<=k;j++){
			cin>>a>>t;
			add(last_a+kth[i],a+kth[i],0);
			add(a+kth[i],last_a+kth[i],0);
		}
	}
	return 0;
}