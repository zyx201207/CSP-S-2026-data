#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long cnt;
string s;
struct node{
	int ai;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ai>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		int minn=min(a[l].ai,a[r].ai);
		if(a[l].c!=a[r].c) cnt+=minn;
		a[l].ai-=minn;
		a[r].ai-=minn;
		if(a[l].ai==0) l++;
		if(a[r].ai==0) r--;
	}
	cout<<cnt;
	
	
	return 0;
}