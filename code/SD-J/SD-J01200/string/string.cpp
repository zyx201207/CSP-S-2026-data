#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node{
	long long num;
	char id;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long longg=0,cnt=0;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num>>a[i].id;
		for(long long j=longg+1;j<=longg+a[i].num;j++){
			s[j]=a[i].id;
		}
		longg+=a[i].num;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(long long i=1;i<=longg/2;i++){
		if(s[i]!=s[longg+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
