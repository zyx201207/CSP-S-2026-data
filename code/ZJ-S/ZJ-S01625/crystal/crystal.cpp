#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n+1,0);
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a.begin()+1,a.end());
	bool B=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[i]){
			B=0;
			break;
		}
	}
	if(B){
		int j=0,x=a[2]-a[1],y=a[2]-a[1];
		while(m){
			if(m<x){
				break;
			}
			m-=x;
			x+=y;
		}
		cout<<min(j+1,n);
		return 0;
	}
	int ans=1;
	if(n<=5000){
		for(int i=2;i<=n;i++){
			int x=m;
			for(int j=i-1;j>0;j--){
				if(x>=a[i]-a[j]) x-=a[i]-a[j];
				else{
					ans=max(ans,i-j);
//					printf("%d~%d  %d\n",j,i,ans);
					break;
				}
				if(j==1){
					ans=max(ans,i-j+1);
//					printf("%d~%d  %d\n",j,i,ans);
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
//	if(n<=5&&m<=10&&ma<=20){
//		
//	}
	return 0;
}
/*

*/
