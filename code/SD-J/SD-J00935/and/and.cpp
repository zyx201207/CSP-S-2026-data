#include<bits/stdc++.h>
using namespace std;
int n,m;
int mx=-1,a[1000000];
void dfs(int g,int yi,int dang){
	//cout<<yi<<endl;
	if(yi==m){
		//cout<<"nno"<<dang<<"  ";
		mx=max(mx,dang);
		return ;
	}
    for(int i=g;i<=n;i++){
    	
    	int h=dang&a[i];
    	//cout<<i<<" "<<yi<<" "<<h<<endl;
		dfs(i,yi+1,h);
		//cout<<"LL";
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,a[1]);
	cout<<mx;
	return 0;
}
