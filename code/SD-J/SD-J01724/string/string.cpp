#include<bits/stdc++.h>
#define st string
#define qw long long
using namespace std; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	qw n,q=0,x=0;
	cin>>n;
	qw a[n+10086],b[123]={0};
	char c[n+10086];
	st s="";
	for(qw i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q+=a[i];
		b[c[i]]++;
	}qw r=0;
	for(qw i=97;i<=122;i++){
		if(b[i]){
			r++;
		}
	}if(r==1){
		cout<<0;
		return 0;
	}for(qw i=1;i<=n;i++){
		for(qw j=1;j<=a[i];j++){
			s+=c[i];
		} 
	}for(qw i=1;i<=q/2;i++){
		if(s[i]==s[q-i+1]){
			x++;
		}
	}cout<<x;
	
return 0;
}
