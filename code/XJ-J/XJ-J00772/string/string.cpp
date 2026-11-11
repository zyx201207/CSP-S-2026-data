#include<bits/stdc++.h>
using namespace std;

long long n,sum=0,l=0;
string a,b;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long q;
		char p;
		cin>>q>>p;
		l+=q;
		for(;q>0;q--)
			a+=p;
	}
	long long mid=(l+1)/2;
	for(long long i=0;i<mid;i++)
		b+=a[i];
	for(long long i=mid-1-l%2;i>=0;i--)
		b+=a[i];
	for(long long i = 0;i<l;i++){
		if(a[i]!=b[i])
			sum++;
	}   
	cout<<sum;
	
	return 0;
}