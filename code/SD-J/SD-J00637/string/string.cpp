#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,a[300005],v[300005],b[300005],m,c,d=1000000000,y,ch[105],z;
string s[300005],u;
void t(){
	u="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[b[i]];j++){
			u+=s[b[i]];
		}
	}
	m=u.size();
	c=0;
	for(int i=0;i<m/2;i++){
		if(u[i]!=u[m-i-1]){
			c++;
		}
	}
	d=min(c,d);
}
void f(LL x){
	if(x>n){
		t();
		return ;
	}
	if(x<=0||x>n){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			b[x]=i;
			x++;
			f(x);
			x--;
			b[x]=0;
			v[i]=0;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		y=max(y,a[i]);
	}
	if(y<=1){
		for(int i=1;i<=n;i++){
			ch[s[i][0]-'a'+1]++;
		}
		for(int i=1;i<=26;i++){
			z+=ch[i]%2;
		}
		cout<<z/2;
	}else{
		f(1);
		cout<<d;
	}
	return 0;
}
//Trick||Treat!
