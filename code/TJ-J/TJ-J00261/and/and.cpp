#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ma,an,ch;
void dfs(int c){
	if(c>m){
		//cout<<an<<' ';
		ma=max(ma,an);
		an=ch;
		return;
	}if(c==1){
		for(int i=1;i<=n;i++){
			an=a[i];
			dfs(c+1);
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==an){
				continue; 
			}
			//cout<<an<<' '<<a[i]<<"\n";
			ch=an;
			an=an&a[i];
			dfs(c+1);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dfs(1);
	cout<<ma;
	return 0;
}
