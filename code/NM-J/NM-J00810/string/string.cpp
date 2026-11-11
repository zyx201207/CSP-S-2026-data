#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=sum;i<a+sum;i++){
			s[i]=c;
		}
		sum+=a;
	}
	for(int i=0;i<sum/2;i++){
        long long k=sum-1-i;
		if(s[i]!=s[k]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
