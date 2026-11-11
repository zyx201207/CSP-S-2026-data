#include<bits/stdc++.h>
using namespace std;
long long s[200005];
char d[200005];

long long jj(long long *s,long long *d){
	long long f;
	if(*s>=*d){
		f=*d;
		*s=*s-*d;
		*d=0;
	}
	else{
		f=*s;
		*d-=*s;
		*s=0;
	}
	return f;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,t=0,y;
	cin>>a;
	for(long long i=0;i<a;i++){
		cin>>s[i]>>d[i];
	}long long q=0,w=a-1;
	while(1){
		if(q>=w)break;
		if(d[q]!=d[w]){
			t+=jj(&s[q],&s[w]);
		}
		else y=jj(&s[q],&s[w]);
		if(s[q]<=0)q++;
		if(s[w]<=0)w--;
	}
	cout<<t;
	return 0;
}
