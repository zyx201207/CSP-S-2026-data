#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
ll n,m;
ll a[N];
ll b[N]={0};
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n>5000){
		for(int i=1;i<=n;i++){
			if(b[i]+m>=a[i]*i){
				ans=i;
			}
		}
		
	}
	else{
		for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(b[i]-b[j-1]+m>=a[i]*(i-j+1)){
				
				ans=max(ans,(ll)i-j+1);
			}
		}	
	}
	}
	
	cout<<ans;
	return 0;
}

