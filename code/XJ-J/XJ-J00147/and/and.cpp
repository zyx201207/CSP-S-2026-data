#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin.tie(0),cout.tie(0);
	int n,m,a[1000],c=0,b[1000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>c){
			c=a[i];
			for(int j=1;j<=n;j++){
				b[j]=c;
			}
		}
	}
	cout<<b[m];
	return 0;
} 
