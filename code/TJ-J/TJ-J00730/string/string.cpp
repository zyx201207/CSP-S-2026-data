#include<bits/stdc++.h>
using namespace std;
long long n; 
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	char x;
	long long cs;
	long long zcs=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cs>>x;
		zcs+=cs;
		for(int k=0;k<cs;k++){
			s+=x;
		}
	}
	int l=0;
	long long r=zcs-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;		
	}
	cout<<ans;
	return 0;
}
