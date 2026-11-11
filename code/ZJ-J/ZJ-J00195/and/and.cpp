#include <bits/stdc++.h>
using namespace std;

int n;

int andn(int x,int m,int a[200005]){
	int maxn=0,maxi;
	if(m==0)return x;
	for(int i=1;i<=n;i++){
		if(a[i]&x>maxn){
			maxn=a[i]&x;
			maxi=i;
		}
	}
	if(m==1)return maxn;
	else{
		a[maxi]=0;
		return andn(maxn,m-1,a);
	}
	
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;int a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0,maxi1,maxi2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]&a[j]>maxn&&i!=j){
				maxi1=i;maxi2=j;
				maxn=a[i]&a[j];
			}
		}
	}
	a[maxi1]=0;
	a[maxi2]=0;
	cout<<andn(maxn,m-2,a);
	return 0;
}
