#include<bits/stdc++.h>
using namespace std;
int n,ans=0,ans1=0,ans2=0;
int a[100000];
string b[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		ans+=a[i];
	}
	for(int i=1;i<=n/2+1;i++){
		if(b[i]==b[n-1]){
			ans1++;
		}
	}
	if(ans1==n/2+1){
		cout<<0;
		return 0;
	}
	else if(ans%2==0){
		for(int i=1;i<=n/2;i++){
			if(b[i]!=b[n-i+1]){
				ans1+=a[n-i+1];
			}
		}
	}
	else{
		for(int i=1;i<=n/2;i++){
			if(b[i]!=b[n-i]){
				ans1+=a[n-i+1];
			}
		}
		ans1+=a[n/2+1];
	}
	cout<<ans1/2;
	return 0;
}

