#include <bits/stdc++.h>
using namespace std;
struct poi{
	int m;
	char x;
}a[200010];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].m>>a[i].x;
	int l=1,r=n;
	while(l<=r){
		if(a[l].m>a[r].m){
			a[l].m-=a[r].m;
			if(a[l].x!=a[r].x)ans+=a[r].m;
			r--;
		}else if(a[l].m<a[r].m){
			a[r].m-=a[l].m;
			if(a[l].x!=a[r].x)ans+=a[l].m;
			l++;
		}else{
			if(a[l].x!=a[r].x)ans+=a[l].m;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

