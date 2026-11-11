#include <bits/stdc++.h>
using namespace std;
int n,a[200010],q[200010],p[200010],l,r,qx,px,l1=1,r1=1;
char c[200010],x[200010],y[200010];
long long s,ans,o,m;
int main () {
	ios::sync_with_stdio(0);cin.tie(NULL),cout.tie(NULL);
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];s+=a[i];
	}
	if (s%2) {
		m=s/2+1;
	}
	else {
		m=s/2;
	}
//	cout<<m<<'\n';
	for (int i=1;i<=n;i++) {
		o+=a[i];
		if (s%2) {
			if (o>=m) {
				o-=a[i];
				int rt=(m-o-1),tr=a[i]-(m-o);
				if (rt>tr){
					a[i]=a[i]-tr-tr-1;
					l=i,r=i+1;
				}
				else {
					if (rt==tr) {
						l=i-1,r=i+1;
					}else l=i-1,r=i;
					a[i]=a[i]-rt-rt-1;
				}
				//cout<<"ll";
				break;
			}
		}

		else {
			if (o>=m) {
				//cout<<o<<"d";
				if (o==m) {
					a[i]--,a[i+1]--;
					l=i,r=i+1;
					if (c[i]!=c[i+1]) ans++;
 					//cout<<"adadedad";
				}	
				else {
					o-=a[i];
					int rt=(m-o-1),tr=a[i]-(m-o+1);
					if (rt>tr) {
						a[i]=a[i]-tr-tr-2;l=i,r=i+1;
					//	cout<<"adefwe";
					}
					else if (rt<tr) {
						a[i]=a[i]-rt-rt-2;l=i-1,r=i;
						//cout<<"ffefw";
					}
					else {
						//cout<<"fsfsf";
						l=i-1,r=i+1;
					}
					
				}
				break;
			}
		}
	}
//	cout<<l<<' '<<r<<'\n';
//	for (int i=1;i<=n;i++) {
//		cout<<a[i]<<' '<<c[i]<<'\n';
//	}
	for (int i=l;i>=1;i--) {
		q[++qx]=a[i];x[qx]=c[i];
	}
	for (int i=r;i<=n;i++) {
		p[++px]=a[i];y[px]=c[i];
	}
	//for (int i=1;i<=qx;i++) cout<<q[i]<<' '<<x[i]<<'\n';cout<<'\n';for (int i=1;i<=px;i++) cout<<p[i]<<' '<<y[i]<<'\n';
	while (1) {
		if (x[l1]==y[r1]) {
			int mn=min(q[l1],p[r1]);
			q[l1]-=mn,p[r1]-=mn;
		}
		else {
			int mn=min(q[l1],p[r1]);
			ans+=mn;
			q[l1]-=mn,p[r1]-=mn;
		}
		if (q[l1]==0) l1++;
		if (p[r1]==0) r1++;
		if (l1>l||r1>n) break;
	}
	cout<<ans;
}
//3 2 a 4 b 3 c
//2 2 a 3 a
//3 2 a 2 b 1 c
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
