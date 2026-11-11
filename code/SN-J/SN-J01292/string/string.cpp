#include<bits/stdc++.h>
using namespace std;
long long n,ge=0,qb=1,ans=1;
string a,c,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(long long i=1,shu;i<=n;i++){
	char q;
	cin>>shu>>q;
	for(long long j=1;j<=shu;j++){
		a[++ge]=q;
	}
}
//for(long long j=1;j<=ge;j++){
//		cout<<a[j];
//	}
for(long long i=ge;i>=1;i--){
		c[qb++]=a[i];
	}
	 for(long long i=1;i<=ge;i++){
		if(c[i]!=a[i]){
			ans=0;
		}
	}
	if(ans==1){
		cout<<0;
	}else{
	cout<<1; 
	}
	
	return 0;
} 
/*
3
2 a
2 b
1 c
*/
