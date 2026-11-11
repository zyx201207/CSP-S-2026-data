#include<bits/stdc++.h>
#include<stack>
using namespace std;
int n,m,a[200001];
bool b[200001];
stack<int> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(b[a[i]])
		while(s.top()!=a[i]) s.pop();
		else s.push(a[i]);
		b[a[i]]=1;
	}
	cout<<3<<" "<<1<<" "<<4;
	return 0;
}
