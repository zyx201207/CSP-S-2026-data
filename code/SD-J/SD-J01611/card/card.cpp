#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 yellow1
#define ull unsigned long long
#define rank jkflsfasf
#define time fjklsaflsdfj
inline ll rd(){
	ll k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int lst[300007],ans[300006],f[500007],a[500007];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++){
		a[i]=rd();
		f[i]=1;
		lst[a[i]]=max(lst[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		if(i==lst[a[i]]){
			f[i+1]+=f[i];
			ans[a[i]]=f[i];
		} 
		else f[lst[a[i]]]+=f[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}
// 1 2 1 3
// 1 1 3 4
