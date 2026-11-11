#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,num=0,a;
	string s,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s=s+b;
		}	
		sum=sum+a;
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-1-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
