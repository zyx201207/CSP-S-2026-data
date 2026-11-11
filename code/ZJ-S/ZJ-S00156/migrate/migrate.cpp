#include <bits/stdc++.h>
using namespace std;
int CT,T,n,j,m,nm,i,a[1000001],mi,sa;
void fle(int x,int jl){
	int i;
	if(x==j){
		if(jl<mi){
			mi=jl;
			sa=1;
		}
		else if(jl==mi)sa++;
		return ;
	}
	for(i=x+1;i<=j;i++)
		if(a[i]-a[x]<=m){
			fle(i,jl+1);
		}else return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>CT>>T;
	while(T--){
		cin>>n>>m;nm=0;
		for(i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++){
				mi=2e9;sa=0;
				fle(i,0);
				if(sa==2)nm++;
			}
		cout<<nm<<"\n";
	}
}
