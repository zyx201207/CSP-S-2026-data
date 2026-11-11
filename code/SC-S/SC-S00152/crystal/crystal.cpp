#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans=1;
long long read(){
	long long num=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		num=num*10+(s^48);
		s=getchar();
	}return num*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	long long l=1,r=1;
	unsigned long long nw=0;
	for(int i=2;i<=n;i++){
		nw+=(r-l+1)*(a[i]-a[i-1]);
		while(nw>m){
			nw-=a[i]-a[l];
			l++;
		}ans=max(ans,r-l+1+1);
		r++;
	}cout<<ans;
	return 0;
}