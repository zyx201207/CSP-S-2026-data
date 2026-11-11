//mahaoyu  yuan dong di er zhong xue SN-J00655
#include<bits/stdc++.h>
using namespace std;
string a;
long long n,d,l=0,sum=0;
string  c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>d>>c;
		l+=d;
		for(long long j=0;j<d;j++){
			a+=c;
		}
	}
	for(long long i=0;i<l/2;i++){
		if(a[i]!=a[l-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
