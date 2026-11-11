#include<bits/stdc++.h>
using namespace std;
int a[2*10^5+1];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int ans=0,ans1,ans2;
	for(int i=0;i<n;i++){
		cin>>a[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			if(a[i]and a[j]>ans){
				ans=a[i]and a[j];
				ans1=i;
				ans2=j;
			}
		}
	}
	cout<<a[ans1]and a[ans2];
	return 0;
}
