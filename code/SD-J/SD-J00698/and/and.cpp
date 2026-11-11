#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	int z,g;
}a[N];
bool cmp(node a,node b){
	if(a.g==b.g) return a.z<b.z;
	return a.g>b.g;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].z;
		int cnt=0,s=a[i].z;
		while(s){
			if(s%2==1) cnt++;
			s/=2;
		}
		a[i].g=cnt;
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].z;
	for(int i=2;i<=m;i++){
		ans&=a[i].z;
	}
	cout<<ans;
	return 0;
}

