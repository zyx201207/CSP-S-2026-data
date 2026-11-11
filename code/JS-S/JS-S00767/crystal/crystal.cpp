#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll n,m;
ll a[N],b[N],c[N];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	c[n-1]=b[n-1];
	for(int i=n-1;i>=1;i--)
		c[i]=c[i+1]+b[i];
	if(n<=5000){
		for(int i=2;i<=n;i++){
			int cnt=0;
			for(int j=1;j<i;j++){
				cnt+=c[i-j]-c[i];
				if(cnt>m)break;
				ans=max(ans,j+1);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	int x=b[1];
	int k=1;
	while(m>=0&&k+1<=n){
		m-=k*x;
		k++;
	}
	if(m<0)cout<<k-1<<endl;
	else cout<<k<<endl;
	return 0;
}
