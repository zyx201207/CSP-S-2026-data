#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c;
	cin>>a>>a;
	while(a--){
		cin>>b>>c;
		cout<<c-1<<'\n';
		while(--b)cin>>c>>c;
	}
	return 0;
} 
