#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long cry[maxn];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>cry[i];
	sort(cry,cry+n);
	cry[n]=1e18;
	unsigned long long num=0;
	int cnt=1,j=0,ans=0;
	for(int i=0;i<n;i++){
		while(num+(cry[j+1]-cry[j])*(j-i+1)<=m && j<n-1){
			num+=(cry[j+1]-cry[j])*(j-i+1);
			j++;
			cnt++;
		}
		ans=max(ans,cnt);
		num-=(cry[j]-cry[i]);
		cnt--;
	}
	cout<<ans;
	return 0;
} 
