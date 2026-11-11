#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("member,in","r",in);
preopen("member,out","w",out);
int n;cin>>n;
for(int i=0;i<=n;i++){
	n[i]++;
}
int m;int>>m;
for(int i=0;i<=n;i++){
	m[i+1]=n[i];
	if(m[i]==n[i]){
		cout<<m[i]+n[i];
	}
	if(n[i]>m[i]){
		cout<<n[i];
	}else{
		cout<<m[i];
	}
}
retun 0;
}
