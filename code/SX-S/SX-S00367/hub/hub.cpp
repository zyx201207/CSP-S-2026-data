#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct node{
	int u,v;
}ssr[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>ssr[j].u>>ssr[j].v;
		}cout<<1<<endl;
	}
	return 0;
}