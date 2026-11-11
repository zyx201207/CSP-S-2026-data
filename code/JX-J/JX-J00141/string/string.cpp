#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void out(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)out(x/10),putchar((x%10)+'0');
	else putchar(x+'0');
}
ll n;
ll a[200005];
ll ch[200005];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		ch[i]=getchar()-'a';
	}
	ll i=1,j=n;
	while(i<j){
		while(a[i]==0&&i<j)i++;
		while(a[j]==0&&i<j)j--;
		if(i==j)break;
		if(ch[i]!=ch[j]){
			if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
			}else{
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
			}
		}else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				a[i]=0;
			}else{
				a[i]-=a[j];
				a[j]=0;
			}
		}
	}
	out(ans);
	return 0;
}