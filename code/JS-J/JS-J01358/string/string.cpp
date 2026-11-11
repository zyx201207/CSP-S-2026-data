#include <bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
string c;
string s;
int b=1;
long long a[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=b;j<=a[i];j++){
			s[j]=c[i];
			b=j+1;	
			}
	}
	if(n%2==0){
		for(int i=1;i<=n;i++){
			if(s[i]!=s[n-i]){
				cnt+=1;
			}
		}
	}
	else{
		for(int i=1;i<=(n-1)/2;i++){
			if(s[i]!=s[n-i]){
				cnt+=1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
