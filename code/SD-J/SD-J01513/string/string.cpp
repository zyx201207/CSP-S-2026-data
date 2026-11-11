#include<bits/stdc++.h>
using namespace std;
string s;
char x;
long long ans,n,lth[2],m;
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>x;
		while(m--)s+=x;
	}lth[0]=(s.size()+1)/2,lth[1]=s.size()-1;
	for(int i=0;i<lth[0];i++)if(s[i]!=s[lth[1]-i])ans++;
	cout<<ans;
	return 0;
}
