#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-1;
	int x=0,y=0,f=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			x++;
		}
		if(a[i]==3){
			y++;
		}
		if(a[i]==2){
			f++;
		}
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(m==1){
		cout<<maxn;	
	}else{
		if(y>=2){
			cout<<3;
		}else if(f>=1&&y>=1){
			cout<<2;
		}else if(y>=1&&x>=1){
			cout<<1;
		}else if(f>=2){
			cout<<2;
		}else if(f>=1&&x>=1){
			cout<<0;
		}else if(x>=2){
			cout<<1;
		}
	}
	

	return 0;
}
