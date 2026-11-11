#include<bits/stdc++.h>
#define endl '\n'
#define lnt long long
using namespace std;
const int N=5e5+10; 
lnt a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;lnt m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int i=1,j=2;
	int ans=1;
	lnt sum=a[2]-a[1];
	while(i<=n&&j<=n){
		if(sum<=m){
			//cout<<'a'<<sum<<' '<<i<<' '<<j<<endl;
			ans=max(ans,j-i+1);
			sum+=(a[j+1]-a[j])*(j-i+1);
			j++;
			
		}
		else{
			//cout<<'b'<<sum<<' '<<i<<' '<<j<<endl;
			sum-=a[j]-a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
 
