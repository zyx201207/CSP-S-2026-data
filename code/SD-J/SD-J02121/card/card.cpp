#include <iostream>
#include <cstdio>
using namespace std;
int n,m,mp[500005];
int type[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>mp[i]; 
		type[mp[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<type[i]<<' ';
	}
	cout<<endl;
	return 0;
}
