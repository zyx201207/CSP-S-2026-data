#include<bits/stdc++.h>
using namespace std;
int n,x;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
char c[n+1];
long long qz[n+1],sum=0;
qz[0]=0;
for(int i=1;i<=n;i++){
	cin>>x>>c[i];
	qz[i]=qz[i-1]+x;
}
x=1;
int m=n;
for(int i=1;i<=(qz[n]+1)/2;i++){
	if(i>qz[x]){
		x++;
	}
	if(qz[n]-i+1<=qz[m-1]){
		m--;
	}
	if(c[x]!=c[m]){
		sum++;
	}
}
cout<<sum;
return 0;
}

