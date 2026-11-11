//crystal
#include<bits/stdc++.h>
#define int long long
const int N=5e5+100;
using namespace std;
int n,m,a[N],maxx=-1;
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
	
	int l=1,sum=0,num=0;
	for(int i=1;i<=n;i++){
		sum+=num*(a[i]-a[i-1]);
		num++;
		
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
			num--;
		}
		
		maxx=max(maxx,num);
		
	}
	
	cout<<maxx;
	
	return 0;
}
