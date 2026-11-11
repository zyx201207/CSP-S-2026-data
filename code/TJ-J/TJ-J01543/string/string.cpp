#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char c;
};
node a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	long long cnt=0;
	while(l<r){
		long long v=min(a[l].x,a[r].x);
		a[l].x-=v;
		a[r].x-=v;
		if(a[l].c!=a[r].c){
			cnt+=v;
		}
		if(a[l].x==0){
			l++;
		} 
		if(a[r].x==0){
			r--;
		} 
	}
	cout<<cnt;
	return 0;
}
//zsy 
