#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0;
	char b;
	string S="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			S+=b;
		}
	}
	
	int len=S.size();
	
	for(int i=1;i<=len;i++){
		if(S[i]!=S[len-i]){
			S[i]=S[len-i];
			cnt+=1;
		}
	}
	cout<<cnt; 
	
	return 0;
}

