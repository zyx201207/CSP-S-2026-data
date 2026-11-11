#include<bits/stdc++.h>
using namespace std;

long long a[200001],w[200001];

bool b[200001][31],can_use[200001];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,k,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			k=1LL<<j;
			if(a[i]>=k){
				w[i]=j;
				break;
			}
		}
		for(int j=0;j<=w[i];j++){
			b[i][j]=a[i]%2;
			a[i]/=2;
		}
		can_use[i]=1;
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++) if(b[j][i]&&can_use[j]) cnt++;
		if(cnt>=m){
			for(int j=1;j<=n;j++) can_use[j]=b[j][i]&&can_use[j];
			ans+=1LL<<i;
		}
	}
	cout<<ans;
}
