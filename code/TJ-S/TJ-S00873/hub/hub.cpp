#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	int a,b,s;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>a>>b;
		}
	}
	for(int i=2;i<=n-1;i++){
		int x=a+b-1-k;
		int y=a-b+1-k;
		s=(x+y)-i;
	}
	cout<<s-2<<endl<<s-1;
	return 0;
}
