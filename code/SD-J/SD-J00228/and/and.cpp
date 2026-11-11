#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int ans,same,ans2;
bool cmp(int x,int y){
	return x>y;
}
map<int,int> mp;
struct node{
	int data;
	int pop;
}b[N];
bool cmp2(node x,node y){
	if(x.data==y.data){
		int p=mp[x.data];
		int q=mp[y.data];
		if(p==q) return x.data>y.data;
		return p>q;
	} 
	return x.pop>y.pop;
}
int poopcount(int x){
	int sum=0;
	while(x>0){
		sum+=x&1;
		x=x>>1; 
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		b[i].data=a[i];
		b[i].pop=poopcount(a[i]);
	} 
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp2);
	ans=a[1];
	for(int i=1;i<=m;i++) ans&=a[i];
	for(int i=1;i<=n;i++){
		if(mp[a[i]]>=m) same=max(same,a[i]);
	}
	ans2=b[1].data;
	for(int i=1;i<=m;i++) ans2&=b[i].data;
	cout<<max(same,max(ans,ans2));
	return 0;
}
