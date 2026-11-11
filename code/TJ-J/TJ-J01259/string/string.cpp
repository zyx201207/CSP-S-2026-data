#include<bits/stdc++.h> 
using namespace std;
int n;
long long a,l=0,x=1,ans=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s[0]=0;
	for(int i=i;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(int j=x;j<=x+a;j++){
			s[j]=c;
		}
		x+=a;
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
