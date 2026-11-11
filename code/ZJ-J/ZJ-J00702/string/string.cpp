#include<bits/stdc++.h> 
using namespace std;
long long s[200010][2];
int n,si;
long long cnt,m;
int search(long long x){
	int t=1;
	while(s[t][0]<x)t++;
	return t;
}
int readint(){
	int c=48,x=0;
	while(true){
		c=getchar();
		if(c<48||c>58)break;
		x=x*10+c-48;
	}
	return x;
}
int readchar(){
	int c=97,x=0;
	while(true){
		c=getchar();
		if(c<97||c>122)break;
		x=c;
	}
	return x-96;
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	if(n>2000){
		getchar();
		for(int i=1;i<=n;i++){
			int x=readint(),c=readchar();
			m+=x;
			if(s[si][1]==c)s[si][0]=m;
			else s[++si][0]=m,s[si][1]=c;
		}
	}else{
		for(int i=1;i<=n;i++){
			int x;
			char c;
			cin>>x>>c;
			m+=x;
			if(s[si][1]==c-'a'+1)s[si][0]=m;
			else s[++si][0]=m,s[si][1]=c-'a'+1;
		}
	}
	for(long long j=1;j*2<=m;){
		int t1=search(j),t2=search(m+1-j);
		long long l=min(s[t1][0]-j+1,m+1-j-s[t2-1][0]);
		if(s[t1][1]!=s[t2][1])cnt+=l;
		j+=l;
	}
	cout<<cnt;
	return 0;
}
