#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll maxn = 5e5+10;
ll a[maxn];
ll b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	ll r=2,c=1;ull d=0;
	int i=1;    
	while(d<=m&&r<=n){
		d+=c*b[r];
		if(d>m){
			d-=c*b[r];
			break;
		}
		r++;
		c++;
	} 
	ans=max(c,ans);
	while((1+i)<n){
		c--;
		d-=a[i+c]-a[i];
		i++;
		while(d<=m&&r<=n){
			d+=c*b[r];
			if(d>m){
				d-=c*b[r];
				break;
			}
			r++;
			c++;
		}                           
		ans=max(c,ans);
	}
	cout<<ans<<endl;
	return 0;
}
