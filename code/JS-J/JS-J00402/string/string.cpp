#include<bits/stdc++.h>
using namespace std;
long long n,L,ans;
char a[200005];
long long pre[200005];
long long mn(long long x,long long y){
	return x<=y?x:y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	char input;
	for(long long i=1,x;i<=n;i++){
		input='s';
		while(input!=' '){
			input=getchar();
			if(input>='0'&&input<='9'){
				x=x*10+input-'0';
			}
		}
		scanf("%c\n",a+i);
		L+=x;
		pre[i]=L;
		x=0;
	}
	int l=1,r=n,i=0,s;
	while(i<L>>1){
		s=mn(pre[l],L-pre[r-1]);
		if(a[l]!=a[r]){
			ans+=s-i;
		}
		i=s;
		if(i==pre[l]){
			l++;
		}
		if(i==L-pre[r-1]){
			r--;
		}
	}
	printf("%lld",ans);
}
