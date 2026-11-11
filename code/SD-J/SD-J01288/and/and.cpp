#include<bits/stdc++.h>
using namespace std;
int n,m,a[200006],s[200006][106],maxx1=-2e9,maxx2=-2e9;
int work(int i,int j){
	int p[206];
	for(int k=1;k<=maxx1;k++){
		p[k]=(s[i][k]==1 && s[j][k]==1);
	}
	sort(p+1,p+maxx1+1);
	int ans=0;
	for(int k=maxx1;k>=1;k--){
		ans+=p[k]*pow(2,k-1); 
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=a[i],len=0;
		while(t>0){
			s[i][++len]=t%2;
			t/=2;
		} 
		maxx1=max(maxx1,len);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxx2=max(maxx2,work(i,j));
		}
	}
	cout<<maxx2;
	return 0; 
}
