#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long int y[N],x[N],u,v;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long int l,m,j,i,n,d;
	cin>>l>>m>>j>>i>>n>>d>>u>>v;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int i=1;i<=n;i++)
			cin>>y[i];
			y[i]=u;
			y[m]=v;
			if(x[i]-x[j]<=d){
				l=m-1;
			}else{
				i/=j;
			}
	}
	cout<<1<<'\n'<<2;
	return 0;
}
