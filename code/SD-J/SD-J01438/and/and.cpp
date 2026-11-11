#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],sumand=2147483647,vis[200005];
bool A=0,B=0;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ceil(log(a[i]+1)/log(2))!=floor(log(a[i]+1)/log(2))){
			A=1;
		}
		if(a[i]!=i-1){
			B=1;
		}
	}
	unsigned long long zongheb=0;
	if(B==0&&ceil(log(n)/log(2))==floor(log(n)/log(2))){
		if(m==1){
			cout<<n-1<<endl;
			return 0;
		}
		for(int i=0;i<=log(n)/log(2);i++){
			if(i>=m){
				zongheb+=pow(2,i);
			}	
		}
		cout<<zongheb<<endl;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		sumand&=a[i];
		vis[i]=1;
	}
	if(A==0){
		cout<<sumand<<endl;
		return 0;
	}
	for(int i=m+1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[j])continue;
			int suma=2147483647;
			for(int k=1;k<=n;k++){
				if((vis[k]||k==i)&&k!=j){
					suma&=a[k];
				}
			}
			sumand=max(suma,sumand); 
		}
	}
	cout<<sumand<<endl;
	return 0;
}

