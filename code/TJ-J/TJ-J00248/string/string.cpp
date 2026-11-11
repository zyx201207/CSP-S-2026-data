#include <bits/stdc++.h>

using namespace std;
#define int long long
struct node{
	int x;
	char c;
}a[200005];
int n;
int cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	while(l<=r){
		if(a[l].c==a[r].c){
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else if(a[r].x>a[l].x){
				a[r].x-=a[l].x;
				l++;
			}else{
				r--;
				l++;
			}
		}else{
			cnt=cnt+min(a[l].x,a[r].x);
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else if(a[r].x>a[l].x){
				a[r].x-=a[l].x;
				l++;
			}else{
				r--;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
