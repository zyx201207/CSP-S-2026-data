#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=2e5+10;
const int M=1e5+10;
/*====================*/
const int INF=0x3f3f3f3f;
const int MOD=998244353;
/*====================*/
int n;
char a[N];
long long  b[N];
long long ans=0;
/*====================*/
void Solve(){
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		cnt+=b[i];
	}
	int l=1,r=n,x=0;
	while(l<=r){
		if(b[l]<b[r]){
			if(a[l]==a[r]){
				x+=b[l];
				b[r]-=b[l];
				l++;
			}else{
				ans+=b[l];
				x+=b[l];
				b[r]-=b[l];
				l++;
			}
		}else{
			if(a[l]==a[r]){
				x+=b[r];
				b[l]-=b[r];
				r--;
			}else{
				ans+=b[r];
				x+=b[r];
				b[l]-=b[r];
				r--;
			}
		}
	}
	cout<<ans;
}
/*====================*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}

