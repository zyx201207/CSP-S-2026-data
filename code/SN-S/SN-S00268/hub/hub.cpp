#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000010],c,t,x,y;
int read(){
	int f=1,ans=0;
	char ch=getchar();
	if(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}	
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return f*ans;
}
void solve(){
	int ans;
	for(int i=0;i<n-1;i++){
		x=read(),y=read();
		ans=ans+x-y;
	}
	cout<<ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		solve();
	}
	return 0;
}
