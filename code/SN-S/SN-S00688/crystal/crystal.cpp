#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[500005];
int cha[500005];
int num=0;
int sum=0;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1]+cha[i-1];
	}
	
	sort(cha+1,cha+n+1,cmp);

	for(int i=1;i<=n;i++){
		num+=cha[i];
		if(num<=m){
			sum++;
		} 
	}
	
	cout<<sum;
	
	return 0;
}
