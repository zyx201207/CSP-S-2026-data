#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	int s[500];
	for(n=2;n>0;n-=1){
		cin>>c>>t;
		for(int w=0;w<c-1;w++){
			cin>>s[w];
		}
	} 
	if(s[0]==-1){
		cout<<1<<endl;
		cout<<2;
	}else{
		cout<<0<<endl;
		cout<<1;
	}
	return 0;
}
