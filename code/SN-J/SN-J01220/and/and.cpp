#include <bits/stdc++.h> 
using namespace std;
int b[1000005];
void c(&int a,int i){
	while(a>0){
		b[i]+=a%2;
		b[i]*=10;
		a/2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[1000005],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		c(a[i],i);
	}
	for(int i=1;i<m;i++){
		if(b[i]%10==b[i+1]%10){
			ans+=b[i]%10;
		}
	}
	return 0;
}

