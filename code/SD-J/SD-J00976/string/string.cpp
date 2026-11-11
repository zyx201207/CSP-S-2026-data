#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long a[1001000];
char b[1001000];
char c[10001000];
long long sum;
long long ssum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	sum=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[sum]=b[i]-48;
			sum++;
		}
	}
	int l=1,r=sum-1;
//	for(int i=1;i<=sum;i++){
//		cout<<c[i];
//	}
	while(l<r){
		if(c[l]==c[r]){
			l+=1;
			r-=1;
		}
		else {
			ssum++;
			l+=1;
			r-=1;
		}
	}
	cout<<ssum<<endl;
	return 0;
} 
//zgh
