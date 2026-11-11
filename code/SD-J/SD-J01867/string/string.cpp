#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long n,a[200005],l=0,r,cnt=0;
string s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;
	return 0;
} 
