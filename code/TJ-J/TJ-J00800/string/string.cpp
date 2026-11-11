#include<bits/stdc++.h>
using namespace std; 
long long ans;
int n,x[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	int i1=1,i2=n;
	while(i1<i2){
		int k=min(x[i1],x[i2]);
		if(c[i1]!=c[i2]){
			ans+=k;
			x[i1]-=k;
			x[i2]-=k;
		}
		
		else{
			x[i1]-=k;
			x[i2]-=k;
		}
		if(x[i1]==0) i1++;
		if(x[i2]==0) i2--;
	}
	cout<<ans;
	return 0;
} 
