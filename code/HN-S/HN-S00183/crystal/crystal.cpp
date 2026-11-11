#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("crystal.in","r",stdin);
	preopen("crystal.out","w",stdout);
	int n,m,a[50000],sum=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i]
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int b=a[i];
		int ans=1,ans1=0;
		for(int j=i-1;i>=i;j--){
			if(b-a[j]>m) return 0;
			if(ans1<b-a[j]){
				ans1++;
			}	
		}
		sum=max(ans1,ans);
	}
	cout<<sum;
	return 0;
}
