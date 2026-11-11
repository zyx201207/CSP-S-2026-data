#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m,ans,Max;
int getand(int x,int y){
	int res=0,cnt=1;
	while(x&&y){
		if((x%2==1)&&(y%2==1)){
			res+=cnt;
		}
		x/=2;y/=2;
		cnt*=2;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	if(m==1){
		cout<<Max;return 0;
	}
	Max=0;
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				Max=max(getand(a[j],a[i]),Max);
			}
		}
		cout<<Max;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<n;i++){		
				ans=getand(a[i],ans);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
