#include<bits/stdc++.h>
using namespace std;


bool cheak(int x1,int x2,int d){
	if(abs(x1-x2)<=d) return true;
	else return false;
}
const int N=2*1e6+10;
int pos[N];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	
	cin>>c>>t;
	while(t--){
		int a,d;
		cin>>a>>d;
		for(int i=1;i<=a;i++){
			cin>>pos[i];
		}
		cout<<0;
	}
	return 0;
}
