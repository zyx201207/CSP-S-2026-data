#include<bits/stdc++.h>
using namespace std;
int n,m,a[200006];
int cmd(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,cmd);
		cout<<a[1];
	}
	if(m==2){
		int big=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int aa=a[i];
				int bb=a[j];
				int neeeee=aa&bb;
				if(neeeee>big){
					big=neeeee;
				}
			}
		}
		cout<<big;
	}	
	return 0;
}
