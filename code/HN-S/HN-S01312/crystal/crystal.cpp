#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt=0,ans=0;
int f(int x,int i){
	if(x>m-cnt)return 1;
	cnt+=x;
	return f(a[i+1]-a[1],++i)+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<f(0,1);
	fclose(stdin);
	fclose(stdout);
	//ys uid:230118859
 
} 
