#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,num[300050];
struct st{
	ll next_id,data,now_id;
}a[500050];
map<ll,ll> mp;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].data;
	}
	for(int i=n;i>=1;i--){
		a[i].next_id=mp[a[i].data];
		mp[a[i].data]=i;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(a[j].next_id!=0){
				j=a[j].next_id;
			}
			else{
				num[a[j].data]++;
				j++;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}

