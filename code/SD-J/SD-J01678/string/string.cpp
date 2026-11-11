#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int a[10001];
	char S;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i];
		cin>>c;
		for(int j=1;j<=a[i];j++){
			S=S+c;
		}
	}
	int b=size.(S);
	for(int i=n;i>=b/2;i--){
		for(int j=1;j<=b/2;j++)
			if(S[i]!=S[j]){
				ans++; 
			}
	}
	cout<<ans;
	return 0;
}
