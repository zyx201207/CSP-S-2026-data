#include<bits/stdc++.h>
#define int long long
using namespace std;
struct A{
	int a;
	char c;
}a[200005];
int n,ans;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].c;
	int l=1,r=n;
	while(l<r){
		if(a[l].a!=a[r].a){
			int al=a[l].a,ar=a[r].a;
			if(al>ar){
				a[l].a=al-ar;
				if(a[l].c!=a[r].c)ans+=ar;
				r--;
			}else{
				a[r].a=ar-al;
				if(a[l].c!=a[r].c)ans+=al;
				l++;
			}
		}else{
			if(a[l].c!=a[r].c)ans+=a[l].a;
			l++,r--;
		}
	}
	
	cout<<ans;
	return 0;
}//10:00
