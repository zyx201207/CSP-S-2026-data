#include <bits/stdc++.h>
using namespace std;
int n,l,r;
long long lt,rt,ans;
bool ll=1,rr=1;
struct nn{
	int t;
	char c;
}a[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i].t>>a[i].c;
	l=1,r=n;
	while(l<=r){
		if(ll)lt+=a[l].t;
		if(rr)rt+=a[r].t;
		//cout<<l<<" "<<r<<" "<<lt<<" "<<rt<<"---\n";
		if(lt>rt){
			if(a[l].c!=a[r].c){
				ans+=rt;
			}
			lt-=rt;
			rt=0;
			--r;
			ll=0,rr=1;
		}
		else if(lt==rt){
			if(a[l].c!=a[r].c){
				ans+=lt;
			}
			++l,--r;ll=rr=1;lt=rt=0;
		}
		else if(rt>lt){
			if(a[l].c!=a[r].c){
				ans+=lt;
			}
			++l;ll=1,rr=0;rt-=lt;lt=0;
		}
		//cout<<l<<" "<<r<<" "<<lt<<" "<<rt<<"---*\n";
	}
	cout<<ans;
	return 0;
}