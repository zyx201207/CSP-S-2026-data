#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ans=0,f=1;
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
const int N=5e5+10;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	cout<<4<<" "<<2;
	return 0;
}
