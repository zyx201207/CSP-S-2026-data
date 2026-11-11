#include<iostream> 
#include<string>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,ans,mx=-1;
ll b[32];
ll h[32];
ll a[200005],a1; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	int tot;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a1=a[i];
		tot=1;
		while(a1>0){
			b[tot]+=a1%2;
			a1/=2;
			tot++; 
		}
		if(mx<a[i]){
			mx=a[i];
		}
	}
	if(n==m){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	} 
	if(m==1){
		ans=mx;
		cout<<ans;
		return 0;
	}
	h[1]=1;
	for(int i=2;i<32;i++){
		h[i]=h[i-1]*2;
	}
	for(int i=1;i<32;i++){
		if(b[i]>=m){
			ans+=h[i];
		}
	}
	cout<<ans;
	return 0;
}
