#include<bits/stdc++.h>
using namespace std;
long long tot,n,a,x;
char c;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s1[++tot]=c;
		}
	}
	for(int i=1;i<=tot;i++){
		s2[i]=s1[tot-i+1];
		if(s1[i]!=s2[i]){
			s2[i]=s1[i];
			s1[tot-i+1]=s1[i];
			x++;
		}
	}
	cout<<x;
	return 0;
}
