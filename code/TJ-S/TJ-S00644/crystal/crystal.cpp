#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+10;
int n,m,a[N],cha[N]={0},sum=0,cnt=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cha[1]=a[2]-a[1];
	sum=cha[1];
	for(int i=2;i<n;i++){
		cha[i]=a[i+1]-a[i];
		sum+=(i*cha[i]);
		cnt++;
		if(sum>m){
			cout<<cnt<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}

