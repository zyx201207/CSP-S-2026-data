#include<bits/stdc++.h>
using namespace std;
int n,m,maxnn=INT_MIN;
void f(int m,vector<int> a,int p){
	vector<int> t(n+1,0);
	for(int i=p+1;i<=n;i++){
		t[i]=t[i-1]+a[i];
	}
	
	maxnn=INT_MIN;
	for(int i=p;i<=n-1;i++){
		for(int j=n-1;j>=i;j--){
			if(t[j]-t[i]==m){
				maxnn=max(j-i+1,maxnn);
				//cout<<"find:"<<maxnn<<" l:"<<i<<" r:"<<j<<endl;
			}
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n+1,0),b(n+1,0);
	vector<vector<int>> c(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	int maxn=INT_MIN;
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n;j++){
			c[i][j]=b[j]*(j-i+1);
		}
	}
	for(int i=1;i<=n-1;i++){
		//for(int j=i;j<=n;j++){
			f(m,c[i],i-1);
			maxn=max(maxn,maxnn);
			//cout<<maxn<<endl;
		//}
	}
	
	cout<<maxn;
	return 0;
	
}