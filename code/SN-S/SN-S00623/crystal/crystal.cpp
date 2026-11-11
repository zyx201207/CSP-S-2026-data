#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pp[500005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		pp[i]=a[i-1]-a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int plus=0,sum=0,ans1=0;
		for(int j=i;j<=n;j++){
			if(sum+plus>m){
				ans=max(ans,ans1);
				break;
			}
			sum+=plus;
			plus+=pp[j+1];
			ans1++;
			//cout<<sum<<" "<<plus<<" "<<ans<<endl;
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
