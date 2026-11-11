#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
string s="", s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s1;
		cin>>a>>s1;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
	}
	s2=s;
	for(int i=0,j=s.size()-1;i<j;i++,j--)if(s2[i]!=s2[j])ans++;
	cout<<ans;
	return 0;
}
