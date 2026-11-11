#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string str[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	long long n,sum=0,ans=0,l=0,st=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>s;
		for(long long j=1;j<=a[i];j++){
			str[st]=s;
			st++;
			sum++;
		}
	}
	l=sum;
	for(long long i=1;i<=sum;i++){
		if(str[i]!=str[l]){
			ans++;
			str[l]=str[i];
		}
		l--;
	}
	cout<<ans;
	return 0;
}
