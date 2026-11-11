#include<bits/stdc++.h>
using namespace std;
int main(){ 
	int c,n,m,d,q,a[100],s[1000][1000],b,x,y,sum=0;
	int i;
	cin>>c>>n>>m>>d>>q;
	for(int k=1;k<=m;k++){
		cin>>a[k];
	}
	for(int j=1;j<=n;j++){
		cin>>b;
		for(int i=1;i<=2*b;i++){
			cin>>s[j][i];
		}
	}
	for(int j=1;j<=n;j++){
		for(i=1;i<=2*b;i++){
			cin>>s[j][i];
		}
		for(int v=1;v<=q;v++){
			cin>>x>>y;
			if(s[j][i]==x){
				sum+=s[j][i+1];
			}
			if(s[j][i]==x){
				sum+=s[j][i+1];
			}
		}
	}
	cout<<sum;

}