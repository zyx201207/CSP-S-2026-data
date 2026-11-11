#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l,r,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	int k;
	if(s.size()%2==1)k=s.size()/2+1;
	else k=s.size()/2;
	for(int i=0;i<k;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout<<ans;
}
