#include<bits/stdc++.h>
using namespace std;
int n,a[200010],sum=1000000005;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0,z=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		if(a[i]<sum){
			sum=a[i];
		}
		if(i>=2&&s[i]!=s[i-1]){
			cnt=1;
		}
	}
	if(cnt==0){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			ans++;
		}
	}
	if(ans==0){
		for(int i=2;i<=n;i++){
			if(s[i]!=s[1]){
				z++;
			}
		}
		cout<<z;
		return 0;
	}
	cout<<0;
	return 0;
} 
