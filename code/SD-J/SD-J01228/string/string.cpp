#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int num;
	char c;
}a[N];
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(l==r){
			break;
		}
		if(a[l].num==0){
			l++;
		}
		if(a[r].num==0){
			r--;
		}
		if(a[l].num>a[r].num){
			if(a[l].c!=a[r].c){
				ans+=a[r].num;
			}
			a[l].num-=a[r].num;
			r--;
		}else if(a[l].num<a[r].num){
			if(a[l].c!=a[r].c){
				ans+=a[l].num;
			}
			a[r].num-=a[l].num;
			l++;
		}else if(a[l].num==a[r].num){
			if(a[l].c!=a[r].c){
				ans+=a[l].num;
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
