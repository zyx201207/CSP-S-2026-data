#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	long long a;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	int m=s.size(),sum=0;
	int t=m-1,k;
	if(m%2==0){
		k=m/2;
	}else{
		k=(m+1)/2;
	}
	for(int i=0;i<k;i++){
		if(s[i]!=s[t]){
			sum++;
		}
		t--;
	}
	cout<<sum;
	return 0;
}
