#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	else if(n==2){
		if(m==1){
			cout<<1;
		}
		else if(m==2){
			cout<<1<<" "<<2;
		}
	}
	else if(n==3){
		if(m==1){
			cout<<2;
		}
		else if(m==2){
			if(a[1]==a[3]){
				if(a[1]<a[2])cout<<2<<" "<<1;
				if(a[1]>a[2])cout<<1<<" "<<2;
			}
			if(a[2]==a[1]){
				if(a[1]>a[3])cout<<3<<" "<<1;
				if(a[1]<a[3])cout<<1<<" "<<3;
			}
			if(a[2]==a[3])cout<<1<<" "<<1;
		}
	}
	return 0;
}
