#include <bits/stdc++.h>
using namespace std;
long long int n,a,lef,righ,ans;
char b;
string q;
int main(){
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			q+=b;
		}
	}
	if(n==1){cout<<0;return 0;}
	righ=q.size()-1;
	while(lef<righ){
		if(q[lef]!=q[righ])ans++;
		lef++;righ--;
	}
	cout<<ans;
	return 0;
}
