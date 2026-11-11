#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
const int N=500000+5;
gp_hash_table<int,int>mp;
int a[N],cha[N],b[N];
signed main(){
	cin.tie(0);
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int num=1;
	for(int i=1;i<=n;i++){
		if(mp[a[i]]==0){
			b[num]==a[i];
			num++;
			mp[a[i]]++;
		}
		else mp[a[i]]++;
	}
	cout<<num<<endl;
	for(int i=1;i<=n;i++){
		cha[i]=(a[i]-a[i-1])*(i-1)+cha[i-1];
	}
	int i;
	for(i=1;i<=n&&cha[i]<=m;i++);
	cout<<i-1;
	return 0;
}
