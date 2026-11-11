#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len[200050],x,l[200050],r[200050],sl,sr,k,an,cnt;
char c[200050];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&len[i],&c[i]);
		len[i]+=len[i-1];
	}
	for(int i=n;i>=1;i--){
		if(len[i]>len[n]/2) x=i;
	}
	for(int i=1;i<x;i++) l[i]=len[i];
	for(int i=x+1;i<=n;i++) r[i]=len[n]-len[i-1];
	sl=x-1;sr=x+1;
	if(len[n]%2){
		if(len[x]>len[n]/2+1) r[--sr]=len[n]/2;
		if(len[x-1]<len[n]/2) l[++sl]=len[n]/2;
	}else{
		r[--sr]=len[n]/2;
		if(len[x-1]<len[n]/2) l[++sl]=len[n]/2;
	}
	k=n;
	for(int i=1;i<=sl;i++){
		while(k>=sr&&r[k]<l[i]){
			len[++cnt]=r[k];
			if(c[i]!=c[k]) an+=len[cnt]-len[cnt-1];
			k--;
		}
		len[++cnt]=l[i];
		if(c[i]!=c[k]) an+=len[cnt]-len[cnt-1];
	}
	printf("%lld",an);
	return 0;
}