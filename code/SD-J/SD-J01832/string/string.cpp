#include<bits/stdc++.h>
using namespace std;
const int N=1e8+1000;
int n;
long long l,w,e,ans;
long long c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	int a;
	char b;
	cin>>a>>b;
	l+=a;
	if(w+a>=N)a-=1;
	c[w]+=b;
	c[w+a]-=b;
	w+=a;
}
for(int i=1;i<l;i++){
	c[i]+=c[i-1];
//	cout<<c[i]<<" ";
}
e=l/2;
for(int i=0;i<e;i++){
	if(c[i]!=c[l-i-1])ans++;
}
cout<<ans;
	return 0;
}


