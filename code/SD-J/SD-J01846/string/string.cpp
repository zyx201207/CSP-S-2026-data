#include<bits/stdc++.h>
using namespace std;
struct node{
	int n;
	char q;
}p[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,w=0,ans=0;
	string e;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].n>>p[i].q;
		w+=p[i].n;
		for(int j=1;j<=p[i].n;j++){
			e+=p[i].q;
		}
	}
	for(int i=1;i<=(w/2);i++){
		if(e[i-1]!=e[w-i])ans++;
	}
	cout<<ans;
	return 0;
}
