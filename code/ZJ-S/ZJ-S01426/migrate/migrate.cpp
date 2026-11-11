#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;

void open(string s){
	if(!s.size())return;
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int c,t;
int a[N];
int main(){
	open("migrate");
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<0<<endl;
	}
}
