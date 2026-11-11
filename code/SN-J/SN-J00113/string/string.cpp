#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[220000],cnt=0;
	char op[220000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>op[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2&&op[0]!=op[1]){
		int x=min(a[0],a[1]);
		cout<<x;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(op[i]==op[n-i-1]&&a[i]==a[n-i-1]){
			continue;
		}
		if(op[i]!=op[n-1-i]&&a[i]>a[n-i-1]){
			cnt+=a[i];
			int x=a[i]-a[n-i-1];
			a[n-i-1]=a[i];
			op[n-i-1]=op[i];
			a[n-i-2]-=x;
		}
		if(op[i]!=op[n-1-i]&&a[i]<a[n-i-1]){
			cnt+=a[n-i-1];
			int x=a[n-1-1]-a[i];
			a[i]=a[n-i-1];
			op[i]=op[n-1-i];
			a[i+1]-=x;
		}
		if(op[i]!=op[n-1-i]&&a[i]==a[n-i-1]){
			cnt+=a[i];
			op[i]=op[n-1-i];
		}
	}
	cout<<cnt;
	return 0;
}
