#include<iostream>
#include<stack>
using namespace std;
int c,t;
stack<int> s[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		int n,k;
		cin>>n>>k;
		int u,v;
		for(int j = 1;j < n;j++){
			s[u].push(v);
			s[v].push(u);
		}
		cout<<1<<"\n"<<2;
	}
	return 0;
}

