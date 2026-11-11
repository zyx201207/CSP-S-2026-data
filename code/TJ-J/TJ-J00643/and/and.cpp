#include <bits/stdc++.h>
using namespace std;
long long n,m,mxr,mxt,ans;
string tnum[200005];
bool cacheck[200005];
long long num[200005];
string solv(long long a) {
	string b="";
	int k=mxt;
	while(k--) {
		if(a%2) {
			b="1"+b;
		} else {
			b="0"+b;
		}
		a/=2;
	}
	return b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>num[i];
		cacheck[i]=1;
		mxr=max(mxr,num[i]);
	}
	while(mxr>0) {
		mxr=mxr/2;
		mxt++;
	}
	for(int i=1; i<=n; i++) {
		tnum[i]=solv(num[i]);
	}
	for(int j=0; j<mxt; j++) {
		int nty=0;
		for(int i=1; i<=n; i++) {
			if(!cacheck[i]) continue;
			if(tnum[i][j]=='1'){
				nty++;
			}
		}
		if(nty>=m){
			ans+=1<<(mxt-1-j);
			for(int i=1;i<=n;i++){
				if(tnum[i][j]=='0'){
					cacheck[i]=false;
				}
			}
		}else{
			continue;
		}
	}
	cout<<ans;
	return 0;
}
