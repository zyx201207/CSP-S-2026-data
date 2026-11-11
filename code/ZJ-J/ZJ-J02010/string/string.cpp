#include<bits/stdc++.h>
using namespace std;
long long L,a[210000],s[210000],s1[210000],s2[210000],ans;
int n,t,t1,t2;
char c[210000];
long long min(long long x,long long y){
	if(x>y){
		return y;
	}else{
		return x;
	}
}
int erfen(long long x){
	int l=0,r=n+1;
	while(l+1<r){
		int m=(l+r)/2;
		if(s[m]<x){
			l=m;
		}else{
			r=m;
		}
	}
	return r;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		L+=a[i];
		s[i]=s[i-1]+a[i];
	}
	t=erfen(L/2);
	t1=1,t2=1;
/*	while(t1<t&&t2>=t+1){
		if(s[t1]>=L-s[t2-1]){
			while(s[t1]>=L-s[t2-1]&&t1<=t&&t2>=t+1){
				if(c[t1]!=c[t2]){
					ans+=s[t1]+s[t2-1]-L;
				}
				t2--;
			}
		}else{
			while(s[t1]<=L-s[t2-1]&&t1<=t&&t2>=t+1){
				if(c[t1]!=c[t2]){
					ans+=L-s[t2-1]-s[t1];
				}
				t1++;
			}
		}
	}*/
	for(int i=1;i<=n;i++){
		s1[i]=s[i];
	}
	for(int i=1;i<=n;i++){
		s2[i]=L-s[n-i];
	}
	int i=0;
	while(i<=t){
		i=min(s1[t1],s2[t2]);
		if(s1[t1]<s2[t2]){
			while(s1[t1]<=s2[t2]){
				if(c[t1]!=c[n-t2+1]){
					ans+=min(s1[t1+1],s2[t2])-s1[t1];
				}
				t1++;
			}
		}else{
			while(s1[t1]>s2[t2]){
				if(c[t1]!=c[n-t2+1]){
					ans+=min(s2[t2+1],s1[t1])-s2[t2];
				}
				t2++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}