#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005];
int max_=0;
int yu(int a,int b){
	int at[35]={},bt[35]={},ai=0,bi=0,ct[35]={},c=0;
//	cout<<a<<" "<<b<<" ";
	while(a>0){
		at[ai++]=a%2;
		a/=2;
	}
	while(b>0){
		bt[bi++]=b%2;
		b/=2;
	}	
	for(int i=0;i<=max(ai,bi);i++){
		if(at[i]==1&&bt[i]==1){
			ct[i]=1;
		}else{
			ct[i]=0;
		}
	}
	for(int i=max(ai,bi);i>=0;i--){
		c*=2;
		c+=ct[i];
	}
//	cout<<c<<"\n";
	return c;
}
void bl(int t,int on_,int da){
	if(t>=m){
		max_=max(max_,da);
		return ;		
	}
	if(on_>n){
		return;
	}
	for(int i=on_+1;i<=n;i++){
		int da2=yu(da,a[i]);
		bl(t+1,i,da2);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bl(0,0,INT_MAX);
	cout<<max_;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
