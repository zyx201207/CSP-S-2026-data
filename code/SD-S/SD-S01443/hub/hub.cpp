#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long i,n,m,c,t,x,y;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(i = 1;i < n;i++){
			cin>>x>>y;
		}
		cout<<m - 1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
