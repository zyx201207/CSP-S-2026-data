#include<bits/stdc++.h>
using namespace std;
long long n,s,minn;
struct node{
	int x;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
	for(int l=1,r=n;l<r;){
		if(a[l].x==0) l++;
		if(a[r].x==0) r--;
		minn=INT_MAX;
		minn=min(a[l].x,a[r].x);
		if(a[l].c==a[r].c){
			a[l].x-=minn;
			a[r].x-=minn;
		}
		else{
			s+=minn;
			a[l].x-=minn;
			a[r].x-=minn;
		}
	}
	cout<<s;
	return 0;
}
