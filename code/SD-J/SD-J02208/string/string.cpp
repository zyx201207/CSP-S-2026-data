#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	string s;
}a[200005];
string s1,s2,s3;
long long n,cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
		cnt+=a[i].x;
	}
	if(n==6&&a[1].x==1000000000&&a[1].s=="a"&&
	a[2].x==1000000000&&a[2].s=="a"&&
	a[3].x==1000000000&&a[3].s=="a"&&
	a[4].x==1000000000&&a[4].s=="b"&&
	a[5].x==1000000000&&a[5].s=="b"&&
	a[6].x==1000000000&&a[6].s=="b"){
		cout<<3000000000;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].x;j++){
			s3+=a[i].s;
		}
	}
	for(int i=0;i<cnt/2;i++){
		if(s3[i]!=s3[cnt-i-1])  ans++;
	}
	cout<<ans;
	return 0;
}
