#include<bits/stdc++.h>
using namespace std;
const int xy=2222222;
int c,T,n,t,s;
long long m,u[xy];
pair<int,int> v[xy];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		t=0;
		s=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>u[i];
		for(int i=1;i<=n;i++){
			int j=i;
			while(u[j]-u[i]<=m)j++;
			j--;
			v[++t]={i,j};
		}
		sort(v+1,v+t+1);
		for(int i=1;i<t;i++)if(v[i].second-1==v[i+1].first)s++;
		cout<<s<<"\n";
	}
	return 0;
}
