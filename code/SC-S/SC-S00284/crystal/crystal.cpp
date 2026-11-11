#include<bits/stdc++.h> 
#define int long long 
using namespace std;
const int N=5e5+10;
int n,mm,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>mm;
	m=mm;
	int tot=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int mx=-1e9;
	for(int i=1;i<=n;i++){
		int ans=1;
		for(int j=i-1;j>=1;j--){
			if(m-a[i]+a[j]>=0){
				m-=a[i]-a[j];
				ans++;
			}else{
				break;
			}			
		}
		mx=max(ans,mx);
		m=mm;
	}
	cout<<mx;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/