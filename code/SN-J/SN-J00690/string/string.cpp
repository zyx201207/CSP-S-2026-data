// 张杲楹 陕西省西安爱知中学 SN-J00690 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool flag=false;
	string s;
	long long n,num=0;
	cin>>n;
	int a;
	char c;
	for(int i=0;i<=n;i++)
	{
		cin>>a>>c;
		s[i]=c;
		num+=a;
	}
	for(int i=0;i<=n-1;i++){
		if(s[i]==s[i+1]){
			flag=false;
		}else{
			flag=true;
			break;
		}
	}
	if(flag){
		if(num==5){
			cout<<(num/2);
		}else{
			cout<<num/2;
		}
	}else{
		cout<<"0";
	}
	return 0;
}
