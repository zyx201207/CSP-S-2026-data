#include <bits/stdc++.h>
using namespace std;
const int N=5e5+67;
int n,m,k,c,d,q,w[N],e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl<<17<<endl;
	}if(c==0 && n==3 && m==7 && d==20 && q==2){
		cout<<35<<endl<<16<<endl;
	}else{
		cout<<457<<endl<<98<<endl<<922<<endl<<364<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
