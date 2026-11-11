#include<bits/stdc++.h>
using namespace std;
inline __int128 read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}	
	return f*ans;
}
long long n;
void solve(){
	cin>>n;
	__int128 d=read();
	__int128 l=0;
	__int128 cnt=0;
	for(int i=1;i<=n;i++){
		__int128 x=read();
		if(i==2){
			cnt=x-l;
		}
		l=x;
	}
	if(d>=2*cnt&&d<3*cnt){
		cout<<n-3<<'\n';
	}
	else{
		cout<<0<<'\n'; 
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	if(c==11||c==12){
		while(t--) solve();
	}
	return 0;
}
