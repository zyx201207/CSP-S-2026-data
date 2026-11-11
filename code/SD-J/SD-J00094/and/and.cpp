#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int k;
	if(m==1)
		cout<<a[n];
	else if(m==n){
		k=a[1];
		for(int i=2;i<=n;i++){
			k=k and a[i];
		}
		cout<<k;
	}else if(m==2){
		k=-1;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				int w=a[i] and a[j];
				k=max(k,w);
			} 
		}
		cout<<k;
	}
	return 0;
}
