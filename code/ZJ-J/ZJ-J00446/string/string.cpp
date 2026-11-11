#include <bits/stdc++.h>
using namespace std;
struct partneeeeee{
	long long a,c;
}a[200010];
long long n,cnt=0,ans=0,l,r,tmpl=0,tmpr=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		long long ta,tc;
		char cc;
		cin>>ta>>cc;
		tc=cc-'a';
		a[i].a=ta;
		a[i].c=tc;
	}
	l=1;r=n;
	tmpl=a[l].a;tmpr=a[r].a;
	while (l<=r){
		if (tmpl==tmpr){
			if (a[l].c!=a[r].c){
				ans+=tmpr;
			}
			l++;r--;
			tmpl=a[l].a;
			tmpr=a[r].a;
		}else if (tmpl>tmpr){
			tmpl-=tmpr;
			if (a[l].c!=a[r].c){
				ans+=tmpr;
			}
			r--;
			tmpr=a[r].a;
		}else {
			tmpr-=tmpl;
			if (a[l].c!=a[r].c){
				ans+=tmpl;
			}
			l++;
			tmpl=a[l].a;
		}
	}
	cout<<ans;
	return 0;
}