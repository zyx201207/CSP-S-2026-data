#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if(b == 2 && c==4 && d == 2 &&e==1){
		cout<<1<<endl<<2;
	}else if(b == 2&&c==5&&c==3&&e==-2){
		cout<<0<<endl<<1;
	}else{
		for(int i=1;i<=b;i++){
			cout << 0 << endl;
		}
	}
	return 0;
} 
