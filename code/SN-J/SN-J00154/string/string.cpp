#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string S;
	long long a[n+5];
	string c[n+5];
	long long b=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		for(long long j=0;j<a[i];j++){
			S+=c[i];
		}
	}
	long long l=S.size();
	bool op=true;
	for(long long i=0;i<l/2;i++){
		if(S[i]!=S[l-i-1]){
			op=false;
			break;
		}
	}
	if(op==true){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<l/2;i++){
		if(S[i]!=S[l-i-1]){
			b++;
		}
	}
	cout<<b;
	return 0;
}

