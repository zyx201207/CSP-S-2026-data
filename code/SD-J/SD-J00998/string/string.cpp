#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
const int N=1e6+10,M=1e9+10;
const int INF=0x3f3f3f3f3f3f3f3f;
struct Node{
	int x;
	char c;
}a[N];
int ans;
signed main(){ 
	fst;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].x==a[r].x){
			if(a[l].c!=a[r].c){
				ans+=a[l].x;
			}
			l++,r--;
		}else if(a[l].x<a[r].x){
			if(a[l].c==a[r].c){
				a[r].x-=a[l].x;
				l++;
			}else{
				a[r].x-=a[l].x;
				ans+=a[l].x;
				l++;
			}
		}else if(a[l].x>a[r].x){
			if(a[l].c==a[r].c){
				a[l].x-=a[r].x;
				r--;
			}else{
				a[l].x-=a[r].x;
				ans+=a[r].x;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
//aabbc

//aaaaa


