#include <bits/stdc++.h>
using namespace std;
long long f[200010];
char p[200010];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
string s="";
long long n,t,k=0,flag=0,c=0;
char r;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>f[i]>>p[i];
    p[0]=p[1];
    if(p[i]!=p[i-1]){
    	flag=1;
	}
    k=k+f[i];
    for(int j=1;j<=f[i];j++){
    	s=s+p[i];
	}
}
if(n==1){
    cout<<0;
    return 0;
}
if(flag==0){
	cout<<0;
	return 0;
}
if(k%2==1) {
	for(int i=1;i<=k/2;i++){
		if(s[i+k/2]!=s[k/2-i]){
			c++;
		}
	}
}else{
	for(int i=1;i<=k/2;i++){
		if(s[i+k/2-1]!=s[k/2-i]){
			c++;
		}
	}
}
cout<<c;
return 0;
}



