#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	long long a,u,x,y;
}a[500005];
bool cmp(node x,node y){
	return x.a<y.a;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].a;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		a[i].u=a[i].a-a[i-1].a;
	for(long long i=1;i<=n;i++){
		a[i].x=a[i-1].x+a[i].u*(i-1);
		a[n-i+1].y=2*a[n-i+2].y+a[n-i+2].u;
		if(a[i].x<=m)ans=max(ans,i);
		if(a[n-i+1].y<=m)ans=max(ans,i)+1;
	}
	cout<<ans;
	return 0;
}
