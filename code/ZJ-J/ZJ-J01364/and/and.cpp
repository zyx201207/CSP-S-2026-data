#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;
void open(string s){
	if(!s.size())return;
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
bool cmp(int x,int y){
	return x>y;
}
int n,m,ans;
int a[N];
int main(){
	open("and");
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}

