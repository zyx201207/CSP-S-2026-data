#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	int ans=0;
	int apple=1;
	long long a[50004];
	long long b[50004];
	
	cin>>n>>m;
	 
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	/*
	for(int i=a[0];i<=a[n]+n;i++){
		for(int j=0;j<n;j++){
			if(a[j]<=i ){				
				for(int k=0;k<n;k++)
					ans+=i-a[j];
				if(ans==m){
					cout<<ans;
					return 0;
				}
			}
		}
	}
	cout<<ans;
	*/
	for(int i=2;i<m;i++){
		ans+=i;
		apple++;
		if(m<=ans && m>ans-apple){
			cout<<apple;
			return 0;
		}
	}
}
