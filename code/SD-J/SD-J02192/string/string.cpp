#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,sum;
char c;
string s,x;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}for(int i=s.size()-1;i>=0;i--)x+=s[i];
	for(int i=0;i<=n/2;i++){
		if(s[i]==x[i])continue;
		else {
			x[n-i+1]=s[i];
			sum++;
		}
	}cout<<sum;
	return 0;
}//不怎么会,这道题不AC,来个10分也行,暴力出奇迹!
