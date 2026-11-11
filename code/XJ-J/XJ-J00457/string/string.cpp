#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string S;
	long long x=0;
	for(long long i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=0;i<a;i++){
			S+=c;
		}
	}
	long long m=S.size();
	long long l=0,r=m-1;
	for(long long i=0;i<m/2;i++){
		if(S[l]!=S[r]) x++;
		l++;
		r--;
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}