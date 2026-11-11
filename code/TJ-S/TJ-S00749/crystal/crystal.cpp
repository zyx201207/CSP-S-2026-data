#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,i,j,a[100],b,k,sum=0,c,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(j=1;j<=n;j++){
		min(a[j],a[j+1]);
		
	}
	if(n%2==0){
		b=n/2;
	}
	else    b=(n/2+1);
	if(a[b]!=a[b+1]){
		for(k=1;k<=b;k++){
			c=a[b]-a[k];
			sum+=c;
			ans++;
		}
	}
	if(a[b]==a[b+1]){
		for(k=1;k<=b+1;k++){
			c=a[b+1]-a[k];
			sum+=c;
			ans++;
	}
	}
	
	if(sum<=m)
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
	
}
