#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200001],b[200001],l,r,s[200001],e[200001],ans;
string s1,s2,s3,s4;
char c;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s[1]=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c;
		b[i]=c-'a'+1;
		
	}
	l=1,r=n;
	while(l<r) {
		if(a[l]>a[r]) {
			ll q=a[l];
			//ans+=q;
			
			while(q!=0) {
				ll xiu=0,k=r;
				if(q>=a[r]) {
					xiu+=a[r];
					q-=a[r];
					a[r]=0;
					r--;
				} else {
					a[r]-=q;
					xiu=q;
					q=0;
				}
				if(b[k]!=b[l]) {
					ans+=xiu;
				}
				//cout<<1<<endl;
			}
			l++;
		} else if(a[l]<a[r]) {
			ll q=a[r];
			//ans+=q;
			while(q!=0) {
				ll xiu=0,k=l;
				if(q>=a[l]) {
					xiu+=a[l];
					q-=a[l];
					a[l]=0;
					l++;
				} else {
					a[l]-=q;
					xiu=q;
					q=0;
				}
				if(b[r]!=b[k]) {
					ans+=xiu;
				}
				//l++;
				//cout<<2<<endl;
			}
			r--;
		}else if(a[l]==a[r]&&b[l]!=b[r]){
			ans+=a[r];
			l++,r--;
		}else l++,r--;
	}
	cout<<ans<<endl;//Trick||Treat!
	return 0;
}/* */
