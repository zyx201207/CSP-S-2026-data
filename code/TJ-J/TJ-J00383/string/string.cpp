#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string num="";
	int n;
	cin>>n;
	
	int a;
	char c;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			num+=c;
		}
	}
	long long l=num.size();
	long long mid=l/2-1;
	long long ans=0;
	for(long long i=0;i<=mid;i++){
		if(num[l-i-1]!=num[i]) ans++;
	}
	cout<<ans;
	return 0;
}
