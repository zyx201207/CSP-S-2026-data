#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200010],ans; 
int yu(int a,int b){
	int x=1,sum=0;
	while(a>0&&b>0){
		if(a%2==1&&b%2==1){
			sum+=x;
		}
		a/=2;
		b/=2;
		x*=2;
	}
	return sum;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans=yu(ans,a[i]);
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
