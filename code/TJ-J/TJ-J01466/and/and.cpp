#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	int a[n];
	int num=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(m==1){
		cout<<max(a[0],a[n]);
		return 0;
	}
	ans=0;
	num=0;
	if(m==2){
		for(int i=0;i<n;i++){
			num=a[i]&a[i+1];
			if(num>ans){
				ans=num;
			}
		}
		cout<<ans;
		return 0;
	}
	ans=0;
	num=0;
	if(m==n){
		for(int i=0;i<n;i++){
			ans=a[i]&a[i+1];
			num+=ans;
		}
		cout<<num;
		return 0;
	}
	ans=0;
	num=0;
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sum=a[i]&a[i+1];
			ans=sum&a[i+1];
		}
		if(ans>num){
			num=ans;
		}
	}
	cout<<num;
	return 0;
} 
