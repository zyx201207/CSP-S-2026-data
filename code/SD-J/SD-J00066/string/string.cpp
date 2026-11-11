#include<bits/stdc++.h>
using namespace std;
char ch[1000000000];
long long cnt=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++){
			cnt++;
			ch[cnt]=c;
		}
	}
	for(int i=1;i<=cnt/2;i++){
		if(ch[i]==ch[cnt-i+1]){
			;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
