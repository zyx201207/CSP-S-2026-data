#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	string s;
	while(n--){
		long long x;
		char y;
		cin>>x>>y;
		for(long long i=1;i<=x;i++){
			s+=y;
		}
		sum+=x;
	}
	string v=s;
	reverse(s.begin(),s.end());
	long long cnt=0;
	for(long long i=s.size()/2;i<s.size();i++){
		if(s[i]!=v[i]){
		    cnt++;	
		}
	}
	cout<<cnt;
	return 0;
}