#include<bits/stdc++.h>
using namespace std;
struct w{
	long long j;
	char d;
}s[220000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long l=0,n,ans=0,y=0,r;
	cin>>n;
	for (long long i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		s[i].j=a;
		s[i].d=b;
		l+=a;
	}
	for (long long i=0;i<n;i++){
		y+=s[i].j;
		if (y>l/2){
			r=y-l/2;
			y=i;
			break;
		}
	}
	s[y].j-=r;
	long long sum=n-1;
	for (long long i=0;i<=y;i++){
		long long t=0;
		while(s[i].j>0){
			if (s[i].d!=s[sum].d){
				if (s[i].j-s[sum].j<0){
					ans+=s[i].j;
				}
				else{
					ans+=s[sum].j;
				}
			}
			s[i].j-=s[sum].j;
			if (s[i].j>=0) sum--;
			else s[sum].j=-s[i].j;
		}
	}
	cout<<ans;
	return 0;
}
