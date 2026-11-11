#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a>=maxx){
			maxx=a;
		}
	}
	cout<<maxx; 
	return 0;
}


