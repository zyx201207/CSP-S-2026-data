#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int g;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s; 
	long long len=0;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
		len+=a;
	}
	int i=0;
	len-=1;
	while(i<len){
		if(s[i]!=s[len]) ans++;
		i++;
		len--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
