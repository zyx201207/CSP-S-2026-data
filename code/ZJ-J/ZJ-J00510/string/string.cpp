
#include<bits/stdc++.h>
using namespace std;
int n,m[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	bool b=1;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
		if(i>1&&c[i]!=c[i-1])b=0;
	}
	if(b){
		cout<<0;
		return 0;
	}
	else if(n==2&&(m[1]+m[2])%2==0){
		int mi=min(m[1],m[2]);
		int ma=max(m[1],m[2]);
		cout<<min((mi+ma)/2-mi,mi);
		return 0;
	}
	else if(n==2){
		cout<<min(m[1],m[2]);
		return 0;
	}
} 
