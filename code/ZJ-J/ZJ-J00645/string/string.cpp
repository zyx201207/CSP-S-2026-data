#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans;
struct point{
	int x;
	char y;
}a[200010];
int l,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	l=1,r=n;
	while(l<=r){
		if(a[l].y!=a[r].y){
			if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				ans+=a[l].x;
				l++;
			}
			else if(a[l].x==a[r].x){
				ans+=a[l].x;
				l++;
				r--;
			}
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				ans+=a[r].x;
				r--;
			}
		}
		else{
			if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				l++;
			}
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}
			else if(a[l].x==a[r].x){
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}