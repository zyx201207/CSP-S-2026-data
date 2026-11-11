#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+10;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	map<int,int> mp;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		sum+=(a[n]-a[i]);
	}
	if(m>=sum){
		cout<<n;
		return 0;
	}
	int ans=1;
	int cnt=1;
	for(int i=2;i<=n&&m>0;i++){
		if((a[i]-a[i-1])*cnt<=m){
			m-=a[i]-a[i-1];
			ans++;
			cnt++;
			a[i-1]=a[i];
		}
		else if(a[i]-a[i-1]<=m){
			cnt+=m/(a[i]-a[i-1]);
			m-=m/(a[i]-a[i-1]);
			a[i-1]=a[i];
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
}

/*

5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
Oct31==Dec25?
*/
