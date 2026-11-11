#include<bits/stdc++.h>
using namespace std;
struct oo{
	long long x;
	char y;
}a[200005];
long long ans,maxx;
bool c=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<n;i++){
		if(a[i].y!=a[i+1].y){
			c=0;
			break;
		}
	}
	if(c){
		cout<<0;
		return 0;
	}
	c=1;
	for(int i=1;i<=n/2;i++){
		if(!(a[i].x==a[n-i+1].x&&a[i].y==a[n-i+1].y)){
			c=0;
			break;	
		}
	}
	if(c){
		cout<<0;
		return 0; 
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i].x);
		ans+=a[i].x;
	}
	cout<<ans-maxx; 
	return 0;
} 
