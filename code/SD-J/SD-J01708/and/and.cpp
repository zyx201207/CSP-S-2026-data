#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
ll s[200005][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=a[i],j=1;
		while(t>0){
			s[i][j]=t%2;
			t/=2;
			j++;
		}
	}
	for(int i=30;i>0;i--){
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]==1&&s[j][0]==0) cnt++;
		}
		if(cnt>=m){
			s[0][i]=1;
			for(int j=1;j<=n;j++){
				if(s[j][i]==0) s[j][0]=1;
			}
		}
	}
	for(int i=1;i<=30;i++){
		ll k=1;
		for(int j=1;j<i;j++){
			k*=2;
		}
		ans+=s[0][i]*k;
	}
	cout<<ans;
	return 0;
}
