#include<bits/stdc++.h>
using namespace std;
long long n,a,l,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	if(l%2==1){
		for(int i=0;i<ceil(1.0*l/2)-1;i++){
			if(s[i]!=s[l-i-1]){
				ans++;
			}
		} 
	}else{
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]){
				ans++;
			}
		} 
	}
	cout<<ans;
	return 0;
}
