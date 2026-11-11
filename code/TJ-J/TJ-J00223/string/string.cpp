#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long n,a,ans=0,sum=0;
string s,s1,x;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum+=a;
		cin>>x;
		for(int j=1;j<=a;j++){
			s+=x;
		}
	}
	for(int i=0;i<(sum+1)/2;i++){
		if(s[i]!=s[sum-i-1]){
			ans++;
			s[sum-i-1]=s[i];
		}
	}
	cout<<ans;
	return 0;
} 
