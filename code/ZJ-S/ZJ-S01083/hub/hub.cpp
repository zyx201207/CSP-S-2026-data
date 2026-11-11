#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,p;
	cin>>c>>t;
	while(t--){
		p=0;
		int n,k;
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			p+=y/x/x/x;
		}
		cout<<p/2<<"\n";
	}
	return 0;
}
