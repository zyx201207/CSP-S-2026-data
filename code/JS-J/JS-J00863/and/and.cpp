#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200010];
ll b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	ll num;
	for(int i=1;i<=32;i++){
		if(pow(2,i)<=maxn&&pow(2,i+1)>maxn){
			num=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=32;j++){
			if(pow(2,j)<=a[i]&&pow(2,j+1)>a[i]){
				b[i]=j;
				break;
			}
		}
	}
	
	ll ans=0;
	ll res[200010];
	ll pos=0;
	bool flag=false;
	for(ll i=pow(2,num);i>=1;i/=2){
		for(ll j=1;j<=n;j++){
			if(pow(2,b[j])==i&&!flag){
				ans++;
				res[++pos]=a[j];
				
				if(ans>=m){
					flag=true;
					break;
				}
			}
		}
		if(flag) break;
	}
	
	int temp=res[1];
	for(int i=2;i<=pos;i++){
		temp=temp&res[i];
	}
	cout<<temp;
	return 0;
}
