#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n;
int num[N];
char c[N];
int nosum[N],resum[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
		len+=num[i];
		nosum[i]=nosum[i-1]+num[i];
	}
	for(int i=1;i<=n;i++){
		resum[i]=resum[i-1]+num[n-i+1];
	}
	int mid=len+1>>1;
	int l=1,r=len;
	char lc=c[1],rc=c[n];
	int lqj=1,rqj=n;
	int ans=0;
	while(l<r){
		if(l>nosum[lqj]){
			lqj++;
			lc=c[lqj];
		}
		if(r<nosum[rqj-1]+1){
			rqj--;
			rc=c[rqj];
		}
		if(lc!=rc)ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
/*
code by Ace
*/

