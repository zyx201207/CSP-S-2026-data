#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	int len=s.size();
	if(len%2==1){
		int t=(len-1)/2;
		for(int i=t-1;i>=0;i--){
			if(s[i]!=s[len-i-1]){
				ans++;
			}
		}
	}else if(len%2==0){
		int t=len/2-1;
		for(int i=t;i>=0;i--){
			if(s[i]!=s[len-i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

