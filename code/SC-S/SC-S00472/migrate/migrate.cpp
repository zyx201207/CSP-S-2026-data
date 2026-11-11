#include<bits/stdc++.h>
using namespace std;
int n,d,lc=0,zlc=0,ans=0,anse=0; 
int a[1000001],da[100001],c[100001];
int zuiduan(int u,int v){
	lc++;
	if(u>=v){
		if(zlc==0){
			zlc=lc;
			ans++;
		} else{
			if(zlc>lc){
				zlc=lc;
				ans=1;
			}else if(zlc==lc) ans++;
		}
		return 0;
	}
	for(int i=1;i<=d;i++) zuiduan(u+i,v);
	return ans;
}
int xuanzhe(int u,int v){
	if(u==v) return 1;
	for(int i=u;i<=v;i++){
		for(int j=i+1;j<=v;j++){
			int f=zuiduan(i,j);
			anse=max(f,anse);
			c[j-i]+=f;
			anse=max(c[j-i],anse);	
			ans=0;
		}
	}
	return anse;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	int c,t;
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		da[j]=xuanzhe(1,n);		
		for(int i=1;i<=n;i++) a[i]=0;
		lc=0,anse=0;
	} 
	for(int i=1;i<=t;i++) cout<<da[i]<<endl;
	return 0;
}