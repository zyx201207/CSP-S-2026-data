#include<bits/stdc++.h>
using namespace std;
long long n,a[200500],sum,ans1,ans2;
char c[200500];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i],sum+=a[i];
		for(long long j=0;j<a[i];j++)s+=c[i];
	}
	for(long long i=0;i<sum/2;i++){
		if(s[i]!=s[sum-1]-i)ans1++;
	}
	for(long long i=sum-1;i>=sum/2;i--){
		if(s[i]!=s[sum-1-i])ans2++;
	}
	cout<<min(ans1,ans2);
}
