#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2e5+1;

int c,tc,n,d,a[N],far[N][2],ans;

ll query(int x){
	ll sum=0,one=far[x][0],two=far[x][1];
	while(one<=n&&two<=n&&one&&two){
		if(far[one][1]==far[two][0])
			sum++;
		one=far[one][0],two=far[two][0];
	}
	return sum;
}

void solve(){
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]-a[i]<=d)
				far[i][0]=j,far[i][1]=j-1;
	for(int i=1;i<=n;i++)
		ans+=query(i);
	cout<<ans<<endl;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>tc;
	while(tc--)
		solve();
}

