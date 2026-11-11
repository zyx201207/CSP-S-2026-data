/*
没时间做了，空悲切 
*/
#include<bits/stdc++.h>

using namespace std;
char s[500000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++){
			s[t]=c;
			t++;
		}
	}
	long long med=t;
	if(med % 2==1){
		med=med/2+1;
	}else{
		med/=2;
	}
	int ans=0;
	for(int i=1;i<=med;i++){
		if(s[i-1]!=s[t-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
