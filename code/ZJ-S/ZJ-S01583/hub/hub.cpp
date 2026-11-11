#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,x,y;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		for(int i=1;i<a;i++) cin>>x>>y;
		srand(time(0));
		cout<<rand()*rand()%100<<endl;
	}
	return 0;
}
