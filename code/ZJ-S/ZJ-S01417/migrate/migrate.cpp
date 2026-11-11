#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d,x[2000005],ans;
int n,t,c;
int getmint(int u,int v){
	int a=u,b,tm=0;
	while(a<v){
		tm++;
		if(x[a+1]-x[a]>d) return 0;
		for(b=a+1;x[b]-x[a]<=d;b++){}
		a=b-1;
	}
	return tm;
}
int gettimes(int u,int v,int tm){
	if(tm==0) return 0;
	if(x[v]-x[u]<=d) return 1;
	int f=0;
	for(int i=u+1;i<v&&x[i]-x[u]<=d;i++){
		f+=gettimes(i,v,tm-1);
		if(f>2) break;
	}
	return f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int kud=0;kud<t;kud++){
		cin>>n>>d;
		ans=0;
		for(int i=0;i<n;i++) cin>>x[i];
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(gettimes(i,j,getmint(i,j))==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}