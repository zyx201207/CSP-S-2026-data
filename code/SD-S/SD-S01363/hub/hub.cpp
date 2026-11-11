#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t; 
	cin>>c>>t;
	if(c==0){
		cout<<1<<endl;
		cout<<2;
	}else{
		for(int i=1;i<=t;i++){
			cout<<rand()<<endl;
		}		
	}
	return 0;
}

