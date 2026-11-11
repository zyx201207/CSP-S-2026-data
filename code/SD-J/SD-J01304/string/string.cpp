#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100010],m=0,tf=0,ans=1;
	string c[100010],b[100010];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(n==1){cout<<0;return 0;}
	for(int i=1;i<=n;i++) m+=a[i];
	if(m==2){
		if(c[1]==c[2]) cout<<0;
		else cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=ans;j<=ans+a[i]-1;j++) b[j]=c[i];
		ans+=a[i];
	}
	ans-=1;
	for(int i=1;i<=ans/2;i++) if(b[i]!=b[ans-i+1]) tf=1;
	if(tf==0){cout<<0;return 0;}
	if(m==3){cout<<1;return 0;}
	if(m==4){
		if(b[1]!=b[4] && b[2]!=b[3]){cout<<2;return 0;}
		else{cout<<1;return 0;}
	}
	if(m==4) {cout<<3;return 0;}
	if(m>=5) cout<<m/2;
	return 0;
} 
