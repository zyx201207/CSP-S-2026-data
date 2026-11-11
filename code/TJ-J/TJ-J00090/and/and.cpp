#include<bits/stdc++.h>
using namespace std;
int n,m,ma,ans;
int a[200010];
bool cmp(int x,int y){
	return x>y; 
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ans=INT_MAX;
	if(m==1){
		cout<<a[0]<<"\n";
		return 0;
	}else if(m==n){
		for(int i=0;i<n;i++)
			ans = ans & a[i];
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				int ans= a[i] & a[j];
				ma=max(ma,ans);
			}
		cout<<ma;
		return 0;
	}else if(m==n-1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j)
					ans = ans & a[j];
			}
			ma=max(ma,ans);
			ans=INT_MAX;
		}
		cout<<ma;
		return 0;
	}else{
		for(int i=0;i<m;i++){
			ans=ans*a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
