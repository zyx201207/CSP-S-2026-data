#include<bits/stdc++.h>
using namespace std;
int a[2000005];
char b[2000005];

int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	long long sum=0,ans=0;
	cin>>n;
	string c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			c+=b[i];
		}
	}
	for(int i=0;i<sum;i++){
		cout<<c[i]; 
	}
	int hw=1;
	int he;
	if(sum%2==0) he=sum/2;
	else he=(sum+1)/2;
	for(int i=0;i<=he;i++){
		if(c[i]!=c[n-i]) hw=0;
	}
	cout<<hw;
	if(hw=0){
		for(int i=0;i<=he;i++){
			if(c[n-i]!=c[i]){
				ans++;
				cout<<"1";
			} 
		}
	}
	cout<<ans;
}
