#include<iostream>
#include<cmath>
using namespace std;
int n,len,l,r;
char c[200005],cc;
long long a[200005],aa,s[200005],ans,si;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa>>cc;
		if(cc!=c[len]){
			c[++len]=cc;
			a[len]=aa;
			s[len]=s[len-1]+aa;
		}
		else{
			a[len]+=aa;
			s[len]+=aa;
		}
		si+=aa;
	}
	l=1,r=len;
	for(long long i=1ll;i<=si/2ll;i+=1ll){
		if(i>s[l]){
			l++;
		}
		if((si-i+1ll)==s[r-1]){
			r--;
		}
		if(c[l]!=c[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//csp 2026 rp++
