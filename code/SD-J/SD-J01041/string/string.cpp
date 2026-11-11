#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];char s[N];
string zui;
int l=0;
string x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=2;i<=n;i++){
		if(s[i]!=s[i-1]){
			f=false;
		}		
	}
	if(f){
		cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		for(long j=1;j<=a[i];j++){
			zui=zui+s[i];
		}
	}
	int sum=0;
	int ll=zui.size()-1;
	for(int i=0;i<=ll/2;i++){
		if(zui[i]!=zui[ll-i]){
			sum++;	
		}
	}
	cout<<sum;
	return 0;
} 

