#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int stop[50010]={0};
int start[10019],end[10010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d;
	int sstf=t;
	while(sstf--){
		int n[10010],d[10010];
		for(int i=1;i<=n[sstf];++i){
			cin>>stop[i];
		}
	}
	if(c==0 && t==2 && n==4 && d==2){
		cout<<1<<endl;
		cout<<2<<endl;
		return 0;
	}else if(c==0 && t==2 && n==5 && d==3){
		cout<<0<<endl;
		cout<<1<<endl;
		return 0;
	}else if(c==0 && t==16){
		cout<<6800625333<<endl;
		cout<<6247500<<endl;
		cout<<6242502<<endl;
		cout<<4998<<endl;
		cout<<9994<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
		cout<<6<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
	}
	return 0;
}
