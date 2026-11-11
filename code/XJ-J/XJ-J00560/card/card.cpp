#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll a[maxn];
ll b[maxn];
ll n,m,k;
map<int,int>mm;
void qc(ll x){
	for(ll i=1;i<x;i++){
		b[i]=0;
	}
	b[1]=b[x];
	b[x]=0;
}
void sr(ll nn){
	ll ai=nn--;
	for(ll i=1;i<=n;i++){
		b[i]=a[nn++];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int s=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		sr(i);
		for(ll j=1;j<=n-i+1;j++){
			for(ll z=1;z<j;z++){
				if(b[j]==b[z]){
					qc(j);
					s=n-i+1-z+1;
				}else{
					s=n-i+1;
				}
			}
		}
		for(ll j=1;j<=s;j++){
			for(ll z=1;z<=m;z++){
				if(b[j]==z){
					mm[z]++;
				}
			}
		}
		cout<<endl;
	}
	for(auto i:mm){
		cout<<i.second<<" ";
	}
	return 0;
}