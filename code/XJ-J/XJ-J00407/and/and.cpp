#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int arr[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int n,m,maxn=-1;
	map<int,int>p;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		maxn=max(maxn,arr[i]);
		p[arr[i]]++;
	}
	if(n<=20){
		sort(arr+1,arr+n+1,cmp);
		int ans=arr[1];
		for(int i=1;i<=m;i++){
			if(p[arr[i]]==1){
				ans=ans&arr[i];
			}
			else if(p[arr[i]]>=m){
					cout<<arr[i];
					return 0;
			}
		}
		cout<<ans;
	}
	if(20<n&&n<=2000){
		if(m==1){
			sort(arr+1,arr+n+1,cmp);
			cout<<arr[1];
		}
		if(m==n){
			int ans=arr[1];
			for(int i=2;i<=n;i++){
				ans=ans&arr[i];
			}
			cout<<ans;
		}
		if(m==2){
			int x,ans,y=-1,z;
			sort(arr+1,arr+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(p[arr[i]]>=m){
						x=arr[i];
						break;
				}
			}
			for(int i=1;i<=n;i++){
				z=arr[i];
				for(int j=i+1;j<=n;j++){
					y=max(y,z&arr[j]);
				}
			}
			ans=max(x,y);
			cout<<ans;
		}
	}
	if(n>2000){
		if(maxn==n-1){
			int ans=arr[n];
			for(int i=n-1;i>=n-m+1;i--){
				ans=ans&arr[i];
			}
			cout<<ans;
		}
		else{
			sort(arr+1,arr+n+1,cmp);
			cout<<arr[m];
		}
	}
}
