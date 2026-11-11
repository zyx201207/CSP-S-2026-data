#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct Node{
	int x;
	char y;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}int l=1,r=n,ans=0;
	while(l<r){
		if(a[l].x>a[r].x){
			if(a[l].y==a[r].y){
				a[l].x-=a[r].x;
				r--;
			}else{
				ans+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
		}else if(a[l].x==a[r].x){
			if(a[l].y==a[r].y){
				l++;
				r--;
			}else{
				ans+=a[r].x;
				l++;
				r--;
			}
		}else{
			if(a[l].y==a[r].y){
				a[r].x-=a[l].x;
				l++;
			}else{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
	}cout<<ans;
	return 0;
}
