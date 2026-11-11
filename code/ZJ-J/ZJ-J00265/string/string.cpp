#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool ok=1;
ll n,a[200007],sum,b[200007],x[200007],ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);


	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	
	for(int i=0;i<=s.size()-1;i++){
		
			if(s[i]!=s[s.size()-i-1])ans++;
		
	}
	cout<<ans/2;
	return 0;
} 

