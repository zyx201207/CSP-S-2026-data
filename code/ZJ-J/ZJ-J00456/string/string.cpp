#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int val,k;
} a[N];
int n,len,l,r,lt,rt,ls,rs,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	IO;
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>a[i].val>>ch;
		len+=a[i].val;
		a[i].k=(int)(ch-'a');
	}
	l=1,r=n;
	lt=0,rt=len;
	while(lt<rt){
		int lr=a[l].val+ls-lt,rr=a[r].val+rs-(len-rt);
		if(lr<=rr){
			ans+=(a[l].k!=a[r].k)*lr;
			ls+=a[l].val;
			l++;
			lt+=lr,rt-=lr;
		}else{
			ans+=(a[l].k!=a[r].k)*rr;
			rs+=a[r].val;
			r--;
			lt+=rr,rt-=rr;
		}
	}
	cout<<ans<<'\n';

	return 0;
}

