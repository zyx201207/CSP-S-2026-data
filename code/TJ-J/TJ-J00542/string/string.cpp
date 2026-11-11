#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	for(int i=s.size()-1,j=0;i>=j;i--,j++){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}//Trick||Treat!
