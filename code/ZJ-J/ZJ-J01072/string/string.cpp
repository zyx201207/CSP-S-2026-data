#include<bits/stdc++.h>
using namespace std;
long long n;
long long  a;
string c;
string ans;
long long  count;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			ans+=c;
		}
	}
	long long cd=ans.length();
	for(int i=1;i<=cd;i++){
		for(int j=cd;j>=1;j--){
			if(ans[i]==ans[j]){
				cout<<"0";
				return 0;
			}
			if(ans[i]==ans[j-2]){
				cout<<n/3+1;
				return 0;
			}
			if(ans[i]==ans[j-1]){
				cout<<n/2;
				return 0;
			}
		}
	}
	return 0;
}
