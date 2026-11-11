#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	int n=0;
	cin>>n;
	char a[20010][2]={};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	int cnt=a[1][1]-48;
	for(int i=2;i<=n+1;i++){
		if(a[i][2]==a[1][2]){
			cnt+=a[i][1]-48;
		}else break;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		num+=a[i][1]-48;
	}
	int ans=0;
	if(num%2!=0 && num!=cnt){
		ans=num-cnt-1;
		cout<<ans;
	}else{
		cout<<num-cnt;
	}
	freopen("string.out","w",stdout);
}
