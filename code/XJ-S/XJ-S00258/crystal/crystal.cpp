#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans = -1e9,maxk = -1e9;
	cin>>n>>m;
	long long a[100100],c[100100];
	 for(int i = 1;i<=n;i++){
	 	cin>>a[i];
	 	maxk = max(maxk,a[i]);
	 }
	 sort(a+1,a+n+1,cmp);
	 for(int i = 1;i<n;i++){
	 	bool flag = 0;
	 	if(m<(a[i+1]-a[i])*i){
	 		flag = 1;
		 }
	 	m-=(a[i+1]-a[i])*i;
	 	for(int j = 1;j<=i;j++){
	 		if(flag){
	 			continue;
			 }
	 		a[j] = a[i+1];
		 }
	 	if(flag){
	 		m = 0;
		 }
	 	if(m<=0){
	 		//cout<<m<<endl;
	 		for(int j = 1;j<=n;j++){
	 			c[a[j]]+=1;
			 }
			 break;
		 }
		 flag = 1;
	 }
	 //sort(c+1,c+n+1);
	 for(int i = 1;i<=maxk;i++){
	 	ans = max(ans,c[i]);
	 }
	 cout<<ans;
	return 0;
} 
