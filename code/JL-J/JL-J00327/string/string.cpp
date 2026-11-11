#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char op[200005];
long long  st[200005],ed[200005];
int l=0;
int len=0;
int ans=0;
int ft=1,lt;
inline long long findf(long long idx){
	while(true){
		if(st[ft]<=idx && idx<=ed[ft]){
			return ft;
		}
		ft++;
	}
}
inline long long finde(long long idx){
	while(true){
		if(st[lt]<=idx && idx<=ed[lt]){
			return lt;
		}
		lt--;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",a+i,op+i);

		//cin>>a[i]>>op[i];
		st[i]=ed[i-1]+1;
		ed[i]=st[i]+a[i]-1;
		len+=a[i];
	}
	lt=n;
	for(long long i=1;i<=len/2;i++){
		int qi=findf(i),qj=finde(len-i+1);
		if(op[qi]!=op[qj]) ans++;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000 a
1000000 a
1000000 a
1000000 b
1000000 b
1000000 b 
*/
