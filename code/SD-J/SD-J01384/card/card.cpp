#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=3e5+10;
struct node{
	int l,r,op;
}vis[N];
bool cmp(node a,node b){
	return a.l<b.l;
}
bool cmp1(int a,int b){
	return a<b;
}
int n,m,a[N],vi[N],tot=0,tott=0,T[M],cf[N],qzh[N],que[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!T[a[i]]) T[a[i]]=i;
		if(T[a[i]]){
			vis[++tot].l=T[a[i]];
			vis[++tot].r=i;
			vis[++tot].op=a[i];
			T[a[i]]=i;
		}
	}
	memset(T,0,sizeof T);
	sort(vis+1,vis+1+tot,cmp);
	for(int i=1;i<=n;i++){
		for(int i=1,smx=1,lp=1,rp=1;i<=n;i++){
			if(i==vis[smx].l){
				que[rp++]=vis[smx++].r;
				sort(que+lp,que+rp,cmp1);
			}
			if(i==que[lp]){
				lp=rp+1,rp++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

