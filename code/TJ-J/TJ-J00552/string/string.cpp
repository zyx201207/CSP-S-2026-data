#include<bits/stdc++.h>
using namespace std;
#define int long long
struct stu{
	int s;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].c;
	while(l<r){
		if(a[l].c != a[r].c) ans+=min(a[l].s,a[r].s);
		if(a[l].s < a[r].s){
			a[r].s-=a[l].s;
			l++;	
		}
		else if(a[l].s > a[r].s){
			a[l].s-=a[r].s;
			r--;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
