#include<bits/stdc++.h>
using namespace std;
int a[500050];
int gz[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int cnt=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=max(cnt,a[i]);
	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int x=m,sum=0;
		for(int j=1;j<=n;j++){
			gz[j]=i-a[j];
		}
		sort(gz+1,gz+n+1);
		for(int j=1;j<=n;j++){
			if(x>0 && x>=gz[j] && gz[j]>=0){
				x-=gz[i];
				sum++;
			}
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
} 
