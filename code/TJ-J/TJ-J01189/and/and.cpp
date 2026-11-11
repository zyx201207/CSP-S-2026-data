#include<bits/stdc++.h>
using namespace std;
int n,m;
int n1,n2;
int maxn;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+5]={};
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxn)maxn=a[i];
		}
		cout<<maxn;
		return 0;
	}
	
	
	for(int i=1;i<=n;i++){
		n1=a[i];
		for(int j=i+1;j<=n;j++){
			n2=a[j];
			if(n1&n2>maxn)maxn=n1&n2;
		}
	}
		
	cout<<maxn;
	return 0;
}
