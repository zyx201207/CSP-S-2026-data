#include<iostream>
using namespace std;
const int N=1e9+5;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		char let;
		cin>>num>>let;
		for(int j=1;j<=num;j++){
			s[len]=let;
			len++;
		}
	}
	len--;
	if((len+1)%2){
		int tp=len/2;//回文中心字符
		for(int i=1;i<=tp;i++){
			if(s[tp-i]!=s[tp+i]){
				ans++;
			}
		}
	}
	else{
		int tp=len/2;
		if(s[tp]!=s[tp+1]){
			ans++;
		}
		for(int i=1;i<=tp;i++){
			if(s[tp-1]!=s[tp+1+i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
