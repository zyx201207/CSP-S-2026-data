#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		int k;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(i==0){
				k=x;
			}
			else{
				k&=x;
			}
		}
		cout<<k;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int mx=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	else{
		int mx=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			mx=max(x,mx);
		}
		cout<<mx;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
