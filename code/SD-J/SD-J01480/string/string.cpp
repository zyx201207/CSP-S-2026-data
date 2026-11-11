#include<cstdio>
#include<iostream>
#include<string>
#define ll long long
using namespace std;
ll n,ans,k,sum;
char a,s[10000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>a;
		for(int j=1;j<=k;j++){
			sum++;
			s[sum]=a;
		}
	}
	for(int i=0;i<=sum/2;i++){
		if(s[i]!=s[sum-i+1])ans++;
	} 
	cout<<ans;
	return 0; 
}
