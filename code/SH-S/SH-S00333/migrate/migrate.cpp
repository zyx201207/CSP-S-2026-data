#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	scanf("%d%d",&c,&t);//c不重要
	while(t--){
		scanf("%d%d",&n,&d);
		int x[n+5];
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		if(n>1 && n%2!=0 &&x[2]-x[1]<d) cout<<"1\n";
		else cout<<"0\n";		
		//？？要求有且仅有两条最短路的u到v 
	}
	return 0;
}
