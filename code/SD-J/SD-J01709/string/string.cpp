#include<bits/stdc++.h>
using namespace std;
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,s=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a>>c;
	for(int j=1;j<=a;j++)
	S+=c;
	}
	for(int i=0;i<=S.size();i++){
	if(S[i]!=S[n-i]) s++;
	}
	cout<<s/2;
	return 0;
}