#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x,cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		x=m;
		cnt=1;
		for(int j=i-1;j>=0;j--){
			x-=a[i]-a[i-j];
			if(x>=0)cnt++;
		}
		if(cnt>ans)ans=cnt;
	}
	cout<<ans;
	return 0;
}