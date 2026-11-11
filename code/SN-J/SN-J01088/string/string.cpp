#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int ans;
struct node{
	int x;
	char k;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].k;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].k==a[r].k){
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				ans+=a[r].x;
				r--;
			}else if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				ans+=a[l].x;
				l++;
			}else{
				ans+=a[l].x;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}



