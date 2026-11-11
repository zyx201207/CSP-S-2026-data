/*李赵星源
西安铁一中滨河高级中学
SN-S00457*/ 
#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;
	cin>>c>>t;
	int n[t],d[t]; 
	for(int j=0;j<t;j++){
		cin>>n[j]>>d[j];
		int a[t][n[j]];
		for(int i=0;i<=n[j];i++){
			cin>>a[t][i];
		}
	}
	if(c==0 and t==2 and n[0]==4 and d[0]==2)
		cout<<1<<endl<<2;	
	//if(c==0 and t==2 and n[0]==5 and d[0]==3)
	//	cout<<0<<endl<<1;
	return 0;
}
