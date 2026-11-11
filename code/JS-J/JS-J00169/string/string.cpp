#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*10*10*10*10*10+33;
int a[MAXN];
string c;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
	}
	else if(n==2){
		if(c[1]!=c[2])cout<<a[2]-a[1];
		else cout<<0;
	}
	
	return 0;
}
