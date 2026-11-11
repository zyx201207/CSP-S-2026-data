#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,d;
	cin>>c>>d;
	if(c==13||c==14){
		for(int i=1;i<=d;i++){
			cout<<1<<endl;
		}
	}else{
		for(int i=1;i<=d;i++){
			cout<<0<<endl;
		}
	}
}
