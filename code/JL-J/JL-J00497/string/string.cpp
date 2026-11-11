#include<bits/stdc++.h>
using namespace std;
long long len,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long int k;
		char a;
		cin>>k>>a;
		for(int j=len;j<=len+k;j++){
			s[j]=a;
		}
		len+=k;
		
	}
	if(true){
		for(int i=1;i<=len/2;i++){
			if(s[i]==s[len+1-i]){
				continue;
			}else{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
