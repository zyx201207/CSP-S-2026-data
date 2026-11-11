#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string a[100005];
	string d[100005];
	long long n,s=0,ans=0;
	cin>>n;
	if(n==1){
		cout<<0;
	}
	int f;
	for(int i=0;i<n;i++){
		cin>>f;
		cin>>a[i];
		for(int j=0;j<s;j++){
			d[s+j-1]=a[i];
		}
		s+=f;
	}
	for(int i=0;i<s/2;i++){
		if(d[s-i-1]!=d[i]){
			ans++;
		}
	}
	cout<<ans;
return 0;}
