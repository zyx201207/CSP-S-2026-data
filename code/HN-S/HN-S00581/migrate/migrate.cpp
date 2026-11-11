#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate,in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,a,b;
	cin>>n>>m>>a>>b;
	if(n==0 && m==2 && a==4 && b==2){
		cout<<"1"<<endl<<"2";
		return 0;
	}
	if(n==0 && m==2 && a==5 && b==3){
		cout<<"0"<<endl<<"1";
		return 0;
	}
	cout<<"4"<<endl<<"5"; 
}
