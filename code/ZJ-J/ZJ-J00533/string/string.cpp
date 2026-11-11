#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],l,r,sl,sr,sum,ans,t;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	l=1,r=n;
	sum/=2;
	while(l-1<=r+1){
		if(sl<sr){
			int x=sr-sl;
			int y=min(a[l],sum-sl);
			if(c[l+1]!=c[r]){
				if(x<=y){
					ans+=x;
					r--;
				}
				else{
					ans+=y;
				}
			}
			l++;
			sl+=y;
		}
		else{
			int x=sl-sr;
			int y=min(a[r],sum-sr);
			if(c[l-1]!=c[r]){
				if(x<=y){
					ans+=x;
					l++;
				}
				else{
					ans+=y;
				}
			}
			r--;
			sr+=y;
		}
	}
	cout<<ans;
	return 0;
}
