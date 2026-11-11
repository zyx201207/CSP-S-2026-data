#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],s,l,sum;
bool flag;
void dfs(int a,int b,int summ){
	if(a==b){
		if(!l) l=summ;
		if(summ==l) s++;
		return ;
	}
	for(int i=n;i>=a+1;i--){
		if(x[i]-x[a]<=d){
			dfs(i,b,summ+1);
			if(s==3) return ;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=3){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				l=0;
				s=0;
				flag=0;
				dfs(i,j,0);
				if(s==2) sum++; 
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
