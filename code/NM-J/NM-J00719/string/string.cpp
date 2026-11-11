#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	int n,a,b=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a>>c;
	b+=a;
	for(int j=1;j<=a;j++){
	S+=c;
	}
	}
	string Z;
	for(int i=b-1;i>=0;i--){
	Z+=S[b];
	}
	if(Z==S) cout<<'0';
	cout<<b/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
