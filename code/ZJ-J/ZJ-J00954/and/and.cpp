#include<bits/stdc++.h>
using namespace std;
int a[200005];
int y;
int n,m;
//void total(int i,int r,int ans){
//	if(r==0){
//		y++;
//		b[y] = ans;
//	} 
//	r--;
//	for(int j = 1;j<=n;j++){
//		int h = ans+a[j];
//		total(i+1,r,h);
//	}
//}
int main(){
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;;
	int a[n+5],maxn = -1;;
	for(int i = 1;i<=n;i++){
		a[i]=0;
		int b;
		cin>>b;
		int c = 0;
		while(b>0){
			a[i]+=(b%2)*pow(10,c);
			b/=2;
			c++;
		}
	}
	int r = m-1;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
		int b = a[i]+a[j];
//		cout<<a[i]<<" "<<a[j]<<" ";
		int c = 0,ans=0;
		while(b>0){
			if(b%10==m){
				ans+=pow(2,c);
			}
			b/=10;
			c++;
		}
//		cout<<ans<<endl;
		maxn = max(ans,maxn);
	}
	}
	cout<<maxn;
}