#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0,ij=0;
	for(int i=0;i<n;i++){
		long long an;
		char am;
		cin>>an>>am;
		sum+=an;
		for(long long j=0;j<an;j++){
			a[ij]=am;
			ij++;
		}
	}
	int sum1=floor(sum/2);
	int s=0;
	for(long long i=ij-1;i>ij-sum1-1;i--)
	if(a[i]!=a[0+sum-ij])
	 s++;
	 cout<<s;
	 return 0;
}