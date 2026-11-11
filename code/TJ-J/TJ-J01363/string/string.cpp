#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long idx=0;
	cin>>n;
	string s="";
	for(int i=1; i<=n; i++) {
		long long x;
		cin>>x;
		char y;
		cin>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
		idx+=x;
	}
	long long mid;
	long long sum=0;
	if(idx%2==0) {
		mid=idx/2;
		for(int i=0;i<mid;i++){
			if(s[i]!=s[idx-i-1]){
				sum++;
			}
		}
	} else {
		mid=idx/2+1;
		for(int i=0;i<mid-1;i++){
			if(s[i]!=s[idx-i-1]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
