#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,uu,vv,v[2000005],u[10000][10000],m,mu[2000005],mmu[2000005],maxa[2000005],kk,maxm=0;
void def(int x){
	if(x<=kk&&min(maxa[x-1]+1,maxa[x])==maxa[x]+1){
		for(int i=1;i<=v[mmu[x]];i++){
		    maxa[x+i]=maxa[x]+1;
    	}
    	maxm=max(maxa[x]+1,maxm);
    	kk=kk+v[mmu[x]];
    	for(int i=1;i<=v[mmu[x]];i++){
    		def(x+i);
		}
	}
}
void abc(int x,int y){
	if(y<=m){
		for(int i=x+1;i<=m;i++){
			mmu[y]=mu[i];
			abc(x,y+1);
		}
	}
	else{
		int a[2000005];
		for(int i=1;i<=n;i++){
			maxa[i]=100000000;
		}
		for(int i=1;i<=k;i++){
			maxa[mmu[i]]=0;
		}
		kk=k;
		def(1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		m=0;
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>uu>>vv;
			v[uu]=v[uu]+1;
			u[uu][v[uu]]=vv;
			v[vv]=v[vv]+1;
			u[vv][v[vv]]=uu;
		}
		for(int j=1;j<=n;j++){
			for(int y=1;y<=v[j];y++){
				if(u[j][y]<=2){
				    m=m+1;
			    	mu[m]=j;
		    	}
			}
		}
		abc(1,1);
		cout<<maxm<<endl;
	}
	return 0;
}