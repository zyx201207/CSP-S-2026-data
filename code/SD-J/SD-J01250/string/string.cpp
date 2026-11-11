#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int n,m,ji=1,ans;
char ch,c[N],x[N],y[N],z[N];
int ada(int hij){
	int ans=0;
	for(int i=1;i<=ji/2;i++){
		if(x[i]!=y[i]){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>ch;
		for(int j=ji;j<=ji+m;j++){
			c[j]=ch;
		}
		ji+=m;
	}
	for(int i=1;i<=ji/2-1;i++){
		x[i]=c[i];
	}
	int op=1;
	if((ji-1)%2!=0){
		for(int i=ji-1;i>=ji/2+1;i--){
			y[op]=c[i];
			op++;
		}
	}
	else{
		for(int i=ji-1;i>=ji/2;i--){
			y[op]=c[i];
			op++;
		}
	}
	ans=max(ans,ada(1));
	for(int i=1;i<=op;i++){
		z[i]=x[i];
	}
	for(int i=1;i<=op;i++){
		x[i]=y[i];
	}
	for(int i=1;i<=op;i++){
		y[i]=z[i];
	}
	ans=max(ans,ada(1));
	cout<<ans;
	
	return 0;
}
