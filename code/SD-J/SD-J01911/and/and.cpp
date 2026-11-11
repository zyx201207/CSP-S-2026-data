#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
	long long a,b;
}a[200005];
bool cmp(node a,node b){
	if(a.b==b.b)return a.a>b.a;
	return a.b>b.b;
}signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a;
		long long cnt=0,x=a[i].a,z=1;
		while(x!=0){
			if(x%2==1)cnt+=z;
			x/=2;
		}a[i].b=cnt;
	}sort(a+1,a+1+n,cmp); 
	if(m==1){
		cout<<a[1].a;
		return 0;
	}long long sum=a[1].a&a[2].a;
	for(long long i=3;i<=m;i++)sum=sum&a[i].a;
	cout<<sum;
	return 0;
}
