#include<bits/stdc++.h>
using namespace std;
const int N=300000;
int n,l,r;
unsigned long long a[N],ans;
char c[N];
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cin>>c[i];
	}
	l=1;r=n;
	while(l<=r){
		if(a[l]>a[r]){
			a[l]-=a[r];
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			r--;
		}else{
			a[r]-=a[l];
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}
