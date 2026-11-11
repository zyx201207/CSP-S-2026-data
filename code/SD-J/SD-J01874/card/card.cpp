#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
const int N=5e5+5;
ll n,m,tot,a[N],b[N],c[N],d[N],ans[N],far[N];
struct node{
	ll l,r,v;
}e[N]; 
bool cmp(node _,node __){
	return _.v>__.v;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(re int i=1;i<=n;i++)cin>>a[i];
	for(re int i=n;i>=1;i--){
		if(b[a[i]])c[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(re int i=1;i<=n;i++){
		if(c[i]){
			e[++tot].l=i;
			e[tot].r=c[i];
			e[tot].v=i;
		}
	}
	sort(e+1,e+1+tot,cmp);
	for(re int i=1;i<=tot;i++){
		for(re int j=e[i].l+1;j<=e[i].r-1;j++){
			if(!d[j])d[j]=e[i].v;
		}
	}
	for(re int i=1;i<=n;i++){
		if(d[i]>=i)continue;//cout<<d[i]<<' ';
		if(d[i]<far[a[i]]){
			ans[a[i]]+=i-far[a[i]];
		}else{
			ans[a[i]]+=i-d[i];
		}
		far[a[i]]=i;
		ans[a[i]]=max(ans[a[i]],i-d[i]);
		
	}//cout<<'\n';
	for(re int i=1;i<=m;i++)cout<<ans[i]<<' ';cout<<endl;
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/ 
