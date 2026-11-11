#include<bits/stdc++.h>
using namespace std;
int n;
char c[200003];
int a[200003];
string s;
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		l+=(long long)a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long cnt=0;
	for(long long i=0;i<l/2+1;i++){
		if(s[i]!=s[l-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
