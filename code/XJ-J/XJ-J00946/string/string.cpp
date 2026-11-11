#include <bits/stdc++.h>
using namespace std;
char b[20000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,flag=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		int ss;
		ss=flag+a;
		for(int i=flag;i<=ss-1;i++){
			b[i]=c;
			flag++;
		}	
	}
	int j=flag-1,cnt=0;
	for(int i=1;i<=j;i++){
		if(b[i]!=b[j]){
			cnt++;
		}
		j--;
	}
	
	cout<<cnt;
	return 0;
}
