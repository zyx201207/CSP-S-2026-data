#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
int n,m,a[N],s[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i]; 
	}
	int ans;
	int x;
	for (int i=1;i<=n;i++){
		x=a[i]*(i-1);
//		cout<<"s:"<<s[i-1]+m<<" x:"<<x<<" i:"<<i<<" a:"<<a[i]<<"\n";
		if ((s[i-1]+m)<x){
			break;
		}
		ans=i;
	}
	cout<<ans;
//	cout<<"\n"<<a[ans]<<' ';
	
	return 0;
}
