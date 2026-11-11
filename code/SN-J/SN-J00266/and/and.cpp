#include<bits/stdc++.h>
using namespace std;

int m,n,a[200000],c[200000],ans;
int ma(int x,int y){
	if(y==0){
		return x;
	}
	for(int i=0;i<m;i++){
		if(c[x^a[i]]!=1){
			c[x^a[i]]=1;
			ma(x^a[i],y-1);
		}
	}
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.ans","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		ans=max(ma(a[i],n),ans);
		
	}
	cout<<ans;
	
}
