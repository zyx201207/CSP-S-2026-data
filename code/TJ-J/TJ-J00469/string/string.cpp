#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
struct node{
	int x;
	char ch;
}a[N];
int min(int ___,int ____){
	return ___<____?___:____;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int _;
		char __;
		cin>>_>>__;
		a[i].x=_;
		a[i].ch=__;
	}int l=1,r=n;
	int ans=0;
	while(l<r){
		if(a[l].x==0) l++;
		if(a[r].x==0) r--;
		int mn=min(a[l].x,a[r].x);
		if(a[l].ch!=a[r].ch){
			ans+=mn;
		}a[l].x-=mn;
		a[r].x-=mn;
	}cout<<ans;
	return 0;
}
