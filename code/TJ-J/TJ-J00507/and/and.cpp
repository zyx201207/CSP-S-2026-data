#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int g=a[i];
		for(int j=1;j<=m;j++){
			for(int k=i+j;k<=n;k++){
				g&=a[k];
			}
		}
		if(g>maxx) maxx=g;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
