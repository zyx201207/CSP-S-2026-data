#include<bits/stdc++.h>
using namespace std;
char s[1000000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	
	int len=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=len;j<len+a;j++){
			s[j]=c;
		}
		len+=a;
	}
	if(len%2==0){
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-1-i]){
				ans++;
			}
		}
	}
	else{
		for(int i=0;i<(len-1)/2;i++){
			if(s[i]!=s[len-1-i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
