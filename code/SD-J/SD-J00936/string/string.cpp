#include<iostream>
#include<string>
using namespace std;
int n,a;
string s,c;
long long len,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<=len;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
			s[len-i-1]=s[i];
		}
	}
	cout<<ans; 
	return 0;
}

