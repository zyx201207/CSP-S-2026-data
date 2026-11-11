#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int x[m+1];
	int y[n+1];	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		x[i]=1;
	}
	int q=0,w=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(y[j]==0){
				continue;
			}
			if(x[i]<a[j]){
				x[i]=a[j];
				a[j]=0;
				a[q]=w;
				w=a[i];
				q=j;
			}
		}	
	}
	int s=x[1];
	for(int i=2;i<=m;i++){
		s=s&x[i];
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
