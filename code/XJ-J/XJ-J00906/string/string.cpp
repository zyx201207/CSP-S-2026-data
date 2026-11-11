#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=0;
	long long r=a.size()-1;
	for(int i=1;i<=n){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		for(long long j=i;j<=a;j++){
			a+=c;
		}
	
	}
	
	while(l<=r){
		if(a[l]=a[r])b++;
		l++;
		r--;
		
	}
	cout<<b;
	return 0;
}