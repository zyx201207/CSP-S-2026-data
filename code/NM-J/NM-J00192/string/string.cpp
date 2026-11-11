#include<bits/stdc++.h>
using namespace std;
long long q=0,ans=0;
int a,c,j=1,x,b[1000005];
char d[1000005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>d[i];
		q+=b[i];
	}
	x=a; 
	while(q>1){
		if(d[j]!=d[x]){
			int u=min(b[x],b[j]);
			b[x]-=u;
			b[j]-=u;
			ans+=u;
			q-=2*u;
		}else{
			int u=min(b[x],b[j]);
			b[x]-=u;
			b[j]-=u;
			q-=2*u;
		}
		if(b[x]==0){
			x--;
		}
		if(b[j]==0){
			j++;
		}
	}
	
	
	cout<<ans;
	return 0;
}

