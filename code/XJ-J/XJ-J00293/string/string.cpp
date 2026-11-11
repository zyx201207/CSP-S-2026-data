#include<bits/stdc++.h>
using namespace std;
int a[200003];
char b[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	long long s=0;
	while(l<r){
		int t=min(a[l],a[r]);
		a[l]-=t;a[r]-=t;
		if(b[l]!=b[r])s+=t;
		if(a[l]==0)l++;
		else r--;
	}
	cout<<s;
	return 0;
} 
