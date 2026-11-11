#include<bits/stdc++.h>
using namespace std;

int main(){
	
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	if(m==1) {cout<<0;return 0;}
	if(n==1){cout<<0;return 0;}
	if(n==2){
		int a,b;
		cin>>a>>b;
		if(max(a,b)-min(a,b)+1<=m){ cout<<2;return 0;}
		else {cout<<0;return 0;}	
	}
	if(n==3){
		int a[4];
		cin>>a[0]>>a[1]>>a[3];
		sort(a,a+3);
		if((a[1]-a[0]+1)>=m){
			if(2*a[1]==a[2]) {
				cout<<3;
				return 0;
			}if(max(2*a[1],a[3])-min(2*a[1],a[3])+1+(a[1]-a[0]+1)>=m){
				cout<<3;
				return 0;
			}else{
				cout<<2;
				return 0;	
			}
		}
		cout<<3;
		return 0;
	}
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];		
	}
	int flag=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]+1)flag=0;	
	}
	if(flag==1){
		if(m==1){cout<<1;return 0;}
		else if(m==2){
			cout<<2;
			return 0;
		}
	}
	cout<<n;
    fclose(stdin)
    fclose(stdout)
    return 0;
}
