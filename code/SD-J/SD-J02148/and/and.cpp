#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	int x;
	int cnt1;
}a[N];
int n,m;
int ans;
bool cmp(node a,node b){
	if(a.cnt1==b.cnt1) return a.x>b.x;
	return a.cnt1>b.cnt1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		int t=a[i].x;
		while(t!=0){
			int r=t%2;
			t/=2;
			if(r==1) a[i].cnt1++;
		}
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1].x;
	for(int i=2;i<=m;i++){
		ans&=a[i].x;
	}
	cout<<ans;
	return 0;
} 
