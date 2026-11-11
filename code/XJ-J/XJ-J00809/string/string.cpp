#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int main (){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,a[N],m=0;
	char s[N];
	string t="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		m+=a[i];
		for(long long j=1;j<=a[i];j++){
			t+=s[i];
		}
	}
	cout<<t;
	long long sum=0;
	for(long long i=0;i<m/2;i++){
		if(t[i]!=t[m-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
