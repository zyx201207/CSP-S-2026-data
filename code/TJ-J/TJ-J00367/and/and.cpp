#include<bits/stdc++.h>
using namespace std;
int a[2005],ans,n;
int f(int m,int t){
	if(m==0)return pow(2,31)-1;
	if(t==n)return 0;
	else return max(a[t]&f(m-1,t+1),f(m,t+1));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	ans=f(m,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
