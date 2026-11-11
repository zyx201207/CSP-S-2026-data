//王子畅 西安市含光中学 SN-J00809 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050];
int maxn=-1;
int tree(int x,int y,int ans){
	if(ans==0){
		return 0;
	}
	if(y==m){
		return ans;
	}else if((n-x+y+1)<m){
		return 0;
	}
	return max(tree(x+1,y+1,(ans&a[x])),tree(x+1,y,ans));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==n){
		int anss=2147483647;
		for(int i=1;i<=n;i++){
			anss=anss&a[i];
		}
		cout<<anss;
	}else{
		cout<<tree(1,0,2147483647);
	}
	return 0;
}

