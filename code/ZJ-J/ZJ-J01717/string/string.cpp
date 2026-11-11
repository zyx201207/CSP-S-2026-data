#include<bits/stdc++.h>
using namespace std;
int n;long long ans;
struct N{
	long long x;
	char y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	int l=1,r=n;
	while(l!=r){
		if(a[l].x>=a[r].x){
			a[l].x-=a[r].x;
			if(a[l].y!=a[r].y)ans+=a[r].x;
			r--;
		}
		else{
			a[r].x-=a[l].x;
			if(a[l].y!=a[r].y)ans+=a[l].x;
			l++;
		}
	}
	cout<<ans;
}