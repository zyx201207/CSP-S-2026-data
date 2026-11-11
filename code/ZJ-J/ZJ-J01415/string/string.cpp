#include<bits/stdc++.h>
using namespace std;
int read(){
	int t=1,l=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		l=l*10+ch-'0';
		ch=getchar();
	}
	return t*l;
}
const int MX=2e5+5;
int n;
long long ans;
int a[MX],h=1,t;
char c[MX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	t=n;
	for(int i=1;i<=n;i++){
		a[i]=read();
		scanf("%c",&c[i]);
	}
	while(h<t){
		if(c[h]==c[t]){
			if(a[h]>a[t]){
				a[h]-=a[t];
				a[t]=0;
				t--;
			}
			else if(a[h]<a[t]){
				a[t]-=a[h];
				a[h]=0;
				h++;
			}
			else{
				a[h]=a[t]=0;
				h++,t--;
			}
		}
		else{
			if(a[h]>a[t]){
				a[h]-=a[t];
				ans+=a[t];
				a[t]=0;
				t--;
			}
			else if(a[h]<a[t]){
				a[t]-=a[h];
				ans+=a[h];
				a[h]=0;
				h++;
			}
			else{
				ans+=a[h]; 
				a[h]=a[t]=0;
				h++,t--;
			}
			
		}
	}
	printf("%lld",ans);
	return 0;
}
