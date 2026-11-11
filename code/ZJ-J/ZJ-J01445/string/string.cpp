#include<bits/stdc++.h>
using namespace std;
#define int long long
struct s{
	int sum;
	char c;
}a[200010];
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].c;
	}
	int t=0;
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].sum>a[r].sum){
				a[l].sum-=a[r].sum;
				a[r].sum=0;r--;
			}
			else{
				a[r].sum-=a[l].sum;
				a[l].sum=0;l++;
			}
		}
		else{
			if(a[l].sum>a[r].sum){
				t+=a[r].sum;
				a[l].sum-=a[r].sum;
				a[r].sum=0;r--;
			}
			else{
				t+=a[l].sum;
				a[r].sum-=a[l].sum;
				a[l].sum=0;l++;
			}
		}
	}
	cout<<t;
}