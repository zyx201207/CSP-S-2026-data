#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],ans=0;
char c[200010];
ll read(){
	ll f=1,cnt=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		cnt=cnt*10+ch-'0';
		ch=getchar();
	}
	return f*cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		cin>>c[i];
	}
	ll l=1,r=n;
	while(l<=r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];l++;
		}else if(a[r]<a[l]){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];r--;
		}else{
			if(c[l]!=c[r]) ans+=a[r];
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
/*

*/
