#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("strting.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string b[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	if(n==1)	cout<<0;
	for(int i=0;i<n;i++){
		if(b[i]==b[i+1])    cnt=1;
	}
	
	if(cnt==1)    cout<<0;
	
	
	
	return 0;
}
