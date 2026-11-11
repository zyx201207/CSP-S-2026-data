#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
struct node{
	int x;
	char y;
}a[N];
int n,cnt;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	int l=1,r=n;
	while(l<=r){
		if(a[l].y!=a[r].y) cnt+=min(a[l].x,a[r].x);
		if(a[l].x<a[r].x){
			a[r].x-=a[l].x;
			l++;
		}
		else if(a[l].x>a[r].x){
			a[l].x-=a[r].x;
			r--;
		}
		else if(a[l].x==a[r].x) l++,r--;
	}
	cout<<cnt;
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) s=s+t[i];
	}
	s=" "+s;
	int l=1,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) cnt++;
		l++,r--;
	}
	cout<<cnt;
	*/ 
	return 0;
}

