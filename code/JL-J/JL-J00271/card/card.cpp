#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,t=0;
	cin>>n>>m;
	int a[n],b[n],c[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int x=0;x<n;x++){
		t=0;
		for(int y=x;y<n;y++){
			b[t]=a[y];
			for(int i=0;i<t;i++){
				if(b[t]==b[i]) t=i;
			}
			t++;
		}
		for(int i=0;i<t;i++){
			c[b[i]-1]++;
		}
		
	}for(int i=0;i<m;i++){
			cout<<c[i]<<" ";
		}
}
