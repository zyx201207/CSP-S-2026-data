#include <bits/stdc++.h>
using namespace std;
int s[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,cnt=0,a;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s[++cnt]=b-96;
		}
	}

	for(int i=1;i<=cnt/2;i++){
		if(s[i]!=s[cnt-i+1]){
			sum++;
		}
	}cout<<sum<<endl;
	return 0;
}
