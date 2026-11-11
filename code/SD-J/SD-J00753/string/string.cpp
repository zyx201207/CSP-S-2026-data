#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
struct node{
	int a;char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].a==a[r].a){
				l++;r--;
			}
			else if(a[l].a>a[r].a){
				a[l].a=a[l].a-a[r].a;
				r--;
			}
			else if(a[l].a<a[r].a){
				a[r].a=a[r].a-a[l].a;
				l++;
			}
		}
		else{
			if(a[l].a==a[r].a){
				ans+=a[l].a;
				l++;r--;
			}
			else if(a[l].a<a[r].a){
				a[r].a=a[r].a-a[l].a;
				ans+=a[l].a;
				l++;
			}
			else if(a[l].a>a[r].a){
				a[l].a=a[l].a-a[r].a;
				ans+=a[r].a;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
