#include<bits/stdc++.h>
using namespace std;
int n,m;struct Node{int val=0,logn=0;}a[200005],na[200005];
int my_log(int n){int ans=0;while(n){if(n&1)ans++;n/=2;}return ans;}
void my_sort(int l,int r){
	if(l==r)return;my_sort(l,(l+r)/2);my_sort((l+r)/2+1,r);
	int p1=l,p2=(l+r)/2+1,p3=l;memset(na,0,sizeof(na));
	while(p1<=(l+r)/2&&p2<=r){
		if(a[p1].logn>a[p2].logn||(a[p1].logn==a[p2].logn&&a[p1].val>=a[p2].val))
		{na[p3].val=a[p1].val;na[p3++].logn=a[p1++].logn;}
		else if(a[p1].logn<a[p2].logn||(a[p1].logn==a[p2].logn&&a[p1].val<a[p2].val))
		{na[p3].val=a[p2].val;na[p3++].logn=a[p2++].logn;}
	}while(p1<=(l+r)/2){na[p3].val=a[p1].val;na[p3++].logn=a[p1++].logn;}
	while(p2<=r){na[p3].val=a[p2].val;na[p3++].logn=a[p2++].logn;}
	for(int i=l;i<=r;i++){a[i].val=na[i].val;a[i].logn=na[i].logn;}return;
}int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i].val;a[i].logn=my_log(a[i].val);}
	my_sort(1,n);int ans=a[1].val;
	for(int i=2;i<=m;i++)ans=(ans&a[i].val);
	cout<<ans;
	return 0;
}
