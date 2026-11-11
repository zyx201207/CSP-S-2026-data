#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		int x=1,ans=-1;
		for(int i=1;i<=n;i++,x++){
			int answer=(x==1?a[2]:a[1]);
			for(int j=(x==1?3:2);j<=n;j++){
				if(j==x) continue;
				answer&=a[j];
			}
			ans=max(ans,answer);
		}
		cout<<ans;
		return 0;
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			flag=false;
			break;
		}
	}
	if(flag){
		int cnt=0;
		for(int i=n;i>=0;i-=2,cnt++){
			if(cnt==m){
				cout<<a[i];
			}
		}
	}else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(i==m){
				cout<<a[i];
				return 0;
			}
		}
	}
	return 0;
}
