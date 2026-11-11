#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	srand(0);
	int x=rand()%2;
	if(x){
		for(int i=1;i<=t;i++){
			cout<<i<<'\n';
		}
	}
	else {
		for(int i=1;i<=t;i++){
			cout<<i-1<<'\n';
		}
	}
}
		
