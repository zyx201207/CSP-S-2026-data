#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN=1e9+5;
ll c,t,n,d,x[maxN],d[maxN];
bool A(int xi){
	if(xi+1>n) return true;
	if(d[xi]!=d[xi+1]) return false;
	else return A(xi+1);
	
}




int main(){
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out","w",stdout);	
cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<"\n";
	n=d=0;
	memset(x,INF,sizeof(x));	
		for(int j=1;j<=n;i++) {
		cin>>x[j];
	d[j-1]=x[j]-x[j-1];
		}
	if(A)
	{
		if(d<2*d[1]) cout<<0;
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
	}
	
	
return 0;	
}



