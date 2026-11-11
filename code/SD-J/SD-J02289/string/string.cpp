#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100005];
char str[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num=0;
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>str[i];
		for(long long j=0;j<a[i];j++){
			s+=str[i];
			num++;
		}
	}
	long long ans=0; 
	for(long long i=0;i<num/2;i++){
		if(s[i]!=s[num-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
