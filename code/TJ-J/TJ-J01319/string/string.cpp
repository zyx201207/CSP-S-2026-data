#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,h=1,cnt=0;
	string s;
	cin>>n;
	for(int i =1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[h]=c;
			h++;
		}
	}
	for(int i =1;i<=h/2+1;i++){
		if(s[i]!=s[h-i]){
			s[i]=s[h-i];
			cnt++;
		}else{
			continue;
		}
	}
	cout<<cnt;
	return 0;
}

