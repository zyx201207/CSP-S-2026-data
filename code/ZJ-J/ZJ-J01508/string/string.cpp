#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long n,L=-1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a>>s1;
		L+=a;
		while(a){
			s+=s1;
			--a;
		}
	}
	long long ans=0;
	for(long long i=0;i<=L/2+1;i++){
		s[L-i]=s[i];
		ans++;	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
