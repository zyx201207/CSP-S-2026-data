#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char c;
string k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)k+=c;
	}
	int r;
	bool p=0;
	if(k.length()%2==1)p=0;
	else p=1;
	int q=k.length()/2-p;
	for(int l=0;l<=q;l++){
		r=k.length()-l-1;
		if(k[l]!=k[r])ans++;
	}
	cout<<ans;
	return 0;
}
