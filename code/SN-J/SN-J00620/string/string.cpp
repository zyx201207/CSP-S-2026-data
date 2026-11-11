#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
char s[200020];
int f =1;
int l=0;
int flag=0;//1:f  2:l
long long ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	l=n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>s[i];
	}
	for(int i=1; i<=n; i++) {
		//	cout<<l<<' '<<f<<' ';
		if(f >=l) {
			break;
		}
		if(s[f]==s[l]) {
			if(a[f]>a[l]) {
				a[f]-=a[l];
				l--;


			} else if (a[f]<a[l]) {
				a[l]-=a[f];
				f++;

			} else {
				f++;
				l--;

			}
		} else {
			if(a[f]>a[l]) {
				ans=ans+a[l]*1ll;
				a[f]-=a[l];
				l--;

			} else if(a[f]<a[l]) {
				ans=ans+a[f]*1ll;
				a[l]-=a[f];
				f++;


			} else {
				
				ans=ans+a[l]*1ll;
				f++;
				l--;
			}
		}
//	cout<<endl;
	}
	cout<<ans;
	return 0;

}
