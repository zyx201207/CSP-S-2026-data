#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long z;
	long long n;
	long long q=0;
	long long ans=0;
	long long len=0;
	cin>>n;
	long long a;
	char b;
	for(int i=1;i<=n;i++){
		cin>>a;
		len+=a;
		cin>>b;
		if(i==1){
			z=b;
		}
		if(i>1&&z!=b){
			q=1;
		}
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	if(q==0){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<=len/2;i++){
		if(s[i]==s[len-i]){
			
		}else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
