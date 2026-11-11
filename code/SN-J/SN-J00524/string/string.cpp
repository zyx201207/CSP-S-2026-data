#include <iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s[1000000000],a;
	string b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		s[i]=a;
	}
	for(int i=1;i<=n;i++){ 
		if(s[i]<s[0]){
			s[0]=s[i];
		}
		if(s[i]<s[1]){
			s[1]=s[i];
		}
	}
	cout<<s[1]+s[0];
	return 0;
}
