#include<bits/stdc++.h>
#define int long long
const int N=2e5+20,inf=0x3f3f3f3f;
typedef long long ll;
using namespace std;
char s[N];
ll x[N];
void solve(){
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
		sum+=x[i];
	}
	ll l=1,r=sum;
	ll i=1,j=n;
	ll cnt=0;
	ll k=x[1],k2=x[n];
	ll maxx;
	if(sum%2==1){
		while(l<sum/2+1 && r>sum/2+1){
		if(s[i]!=s[j]){
			if(k>k2){
				cnt+=k2;
				l+=k2;
				r-=k2;
				k=k-k2;
				j--;
				k2=x[j];
			}else if(k<k2){
				cnt+=k;
				l+=k;
				r-=k;
				k2=k2-k;
				i++;
				k=x[i];
			}else{
				cnt+=k;
				l+=k;
				r-=k;
				i++,j--;
				k2=x[j];
				k=x[i];
			}
		}else{
			if(k>k2){
				l+=k2;
				r-=k2;
				k=k-k2;
				j--;
				k2=x[j];
			}else if(k<k2){
				l+=k;
				r-=k;
				k2=k2-k;
				i++;
				k=x[i];
			}else{
				l+=k;
				r-=k;
				i++,j--;
				k2=x[j];
				k=x[i];
			}
		}
	}
	}
	else{
		while(l<=sum/2 && r>sum/2){
		if(s[i]!=s[j]){
			if(k>k2){
				cnt+=k2;
				l+=k2;
				r-=k2;
				k=k-k2;
				j--;
				k2=x[j];
			}else if(k<k2){
				cnt+=k;
				l+=k;
				r-=k;
				k2=k2-k;
				i++;
				k=x[i];
			}else{
				cnt+=k;
				l+=k;
				r-=k;
				i++,j--;
				k2=x[j];
				k=x[i];
			}
		}else{
			if(k>k2){
				l+=k2;
				r-=k2;
				k=k-k2;
				j--;
				k2=x[j];
			}else if(k<k2){
				l+=k;
				r-=k;
				k2=k2-k;
				i++;
				k=x[i];
			}else{
				l+=k;
				r-=k;
				i++,j--;
				k2=x[j];
				k=x[i];
			}
		}
	}
	}

	cout<<cnt;
	return ;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
