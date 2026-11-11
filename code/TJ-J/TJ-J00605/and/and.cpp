#include<bits/stdc++.h>
using namespace std;
int erjinzhi(int a,int b){
	int x[1001]={},y[1001]={};
	for(int i=30;i>=1;i--){
		if(a>=pow(2,i)){
			x[i]=1;
			a=a-pow(2,i);
		}else{
			x[i]=0;
		}
	}
	for(int i=30;i>=1;i--){
		if(b>=pow(2,i)){
			y[i]=1;
			b=b-pow(2,i);
		}else{
			y[i]=0;
		} 
	}
	int ans=0;
	for(int i=1;i<=30;i++){
		if(x[i]==1&&y[i]==1){
			ans+=2^i;
		}else{
			continue;
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[10001]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	int sum=0;
	cout<<erjinzhi(12,4);
	return 0;
}
