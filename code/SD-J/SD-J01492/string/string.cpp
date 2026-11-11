#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,num;
	long long sum=0,ans=0;
	string s;
	char word;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>word;
		sum+=num;
		for(int j=1;j<=num;j++){
			s+=word;
		}
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
