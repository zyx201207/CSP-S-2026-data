#include<bits/stdc++.h>
using namespace std;
struct node{
	long long id,num,num0; 
}a[200005];
long long m,n,mx=-1e9,wei;
bool cmp(node x,node y){
	long long op=abs(x.num0-wei),oq=abs(y.num0-wei);
	if(op==oq){
		if(x.num==y.num) {
			return x.id>y.id;
		}
		return x.num>y.num;
	}
	return op<oq;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].id;
		long long t=0,x=a[i].id;
		while(x){
			if(x%2==1) a[i].num++;
			a[i].num0++;
			x/=2;
		}
		if(mx<a[i].num){
			mx=a[i].num;
			wei=a[i].num0;
		}
	}
	sort(a+1,a+1+n,cmp);
	long long ans=a[1].id;
	for(int i=2;i<=m;i++) ans=ans&a[i].id;
	cout<<ans;
	return 0;
}