#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],t[200005];
long long ans=0;
inline long long read(){
	int c;long long anss=0;c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		anss=anss*10+c-'0';c=getchar();
	}
	return anss;
}
int main(){
	freopen("string.in","r",stdin);//IMPORTANT
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		int c;c=getchar();
		while(!isdigit(c) && !isalpha(c))c=getchar();
		t[i]=c-'a';
	}
	int c1=1,s1=0,c2=n,s2=0;
	while(c1<c2){
		if(t[c1]!=t[c2]){
			ans+=min(a[c1]-s1,a[c2]-s2);
		}
		if(a[c1]-s1>a[c2]-s2){
			s1+=a[c2]-s2;c2--;s2=0;
		}
		else{
			s2+=a[c1]-s1;c1++;s1=0;
			if(s2==a[c2]){
				c2--;s2=0;
			}
		}
	}
	cout<<ans;
	return 0;
}