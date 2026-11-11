#include <bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char c;
};
node a[200005];
node b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1,s2;
	char c;
	long long n,x,cnt=0,mid,sum=0,sum2=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		b[n-i+1]=a[i];
		sum+=a[i].x;
	};
	mid=sum/2;
	if(sum%2==1) mid++;	
	long long i1=1,i2=1;
	while(sum2<=sum&&(i1<=n||i2<=n)){
		if(a[i1].x==b[i2].x){
			sum2+=a[i1].x*2;
			if(a[i1].c!=b[i2].c) cnt+=a[i1].x;
			i1++;
			i2++;				
		}
		else if(a[i1].x>b[i2].x){
			sum2+=b[i2].x*2;
			if(a[i1].c!=b[i2].c) cnt+=b[i2].x;
			a[i1].x-=b[i2].x;
			i2++;
		}
		else{
			sum2+=a[i1].x*2;
			if(a[i1].c!=b[i2].c) cnt+=a[i1].x;
			b[i2].x-=a[i1].x;
			i1++;
		}
	}
	cout<<cnt;
	return 0;
}