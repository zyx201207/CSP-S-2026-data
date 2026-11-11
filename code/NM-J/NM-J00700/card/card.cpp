#include <bits/stdc++.h>
using namespace std;
int a[500005]={};
int c[300005]={};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int p;
	for(int i=0;i<n;i++){
		int b[300005]={0};
		int j=n-1;
		while((b[a[j]]==0)&&(j>=i)){
			b[a[j]]+=1;
			c[a[j]]+=1;
			j--;
		}
		int g=0;
		int x=j+1;
		
		if(j>i){
			p=0;
		} 
		if(j==i){
			
			while(x<n&&g==0){
				if(a[x]==a[j]){
				p=0;
				g++;
			
			}
			x++;
			}
		}
		int k=j+1;
		while((a[k]!=a[j])&&(k<n)&&(p==0)){
			c[a[k]]-=1;
			k++;
		}
	}
	for(int i=1;i<m;i++){
		cout<<c[i]<<" ";
	}
	cout<<c[m]<<'\n';
	fclose(stdin);
	fclose(stdout);
}
