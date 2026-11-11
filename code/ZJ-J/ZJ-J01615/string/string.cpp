#include<bits/stdc++.h>
using namespace std;
string s;
unsigned long long n,l,ans=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l>>c;
		if(l>100000000){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=l;j++){
			s=s+c;
		}
	}
	int f=0,e=s.size()-1;
	while(f<=e){
		if(s[f]!=s[e])ans++;
		f++;e--;
	}cout<<ans;
	
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
