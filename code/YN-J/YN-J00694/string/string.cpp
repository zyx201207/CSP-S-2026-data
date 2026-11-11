#include<iostream>
using namespace std;//百战征袍不染
struct node{int x;char c;}a[200005];
long long sum;int n,lst,st=1;
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n,lst=n;for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	while(st<=lst){
		if(a[st].x<=a[lst].x){
			if(a[st].c!=a[lst].c)sum+=a[st].x,a[lst].x-=a[st++].x;else a[lst].x-=a[st++].x;
		}else{
			if(a[st].c!=a[lst].c)sum+=a[lst].x,a[st].x-=a[lst--].x;else a[st].x-=a[lst--].x;
		}
	}cout<<sum;
	return 0;}
