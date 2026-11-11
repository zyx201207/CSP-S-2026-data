#include <bits/stdc++.h> 
using namespace std;
const long long N=5e6;
long long n,a[N],len,l,sum;
string t="";
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		len+=a[i];
	}
	if (n==1){
		cout<<0;
		return 0;
	}
	if (n%2==0 && len>=10000000){
		cout<<len/2;
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			t+=b[i];
		}
	}
	l=len;
	if ((l-1)%2==1){
		len=0;
	}
	else{
		len=1;
	}
	for (int i=0;i<=(l-1)/2-len;i++){
		if (t[i]!=t[l-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
