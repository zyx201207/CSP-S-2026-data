#include<bits/stdc++.h>
using namespace std;
long long n;
struct intchar{
	long long int_;
	char char_;
}tt[200009];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	long long k=1;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		tt[i].char_=c;
		tt[i].int_=k;
		k+=x;
	}k-=1;
	tt[n+1].int_=200376420520689663;
	for(long long i=1;i<=k/2;i++){
		char c_='_',c__='_';
		for(long long j=1;j<=n;j++){
			if(tt[j].int_<=i&&tt[j+1].int_>i&&c_=='_'){
				c_=tt[j].char_;
			}if(tt[j].int_<=k-i+1&&tt[j+1].int_>k-i+1&&c__=='_'){
				c__=tt[j].char_;
			}if(c_!='_'&&c__!='_'){
				break;
			}
		}
		if(c_!=c__){
			ans++;
		}
	}cout<<ans;
	
	return 0;
}
