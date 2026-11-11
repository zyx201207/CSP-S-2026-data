#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N],v[N],cnt=0;
void dfs(int step,int anda){
	if(step>m){
		cnt++;
		b[cnt]=anda;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(step+1,anda&a[i]);
			v[i]=0;
		}
	}
	return ;
}
int main(){
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=0;
	}
	dfs(1,2147483647);
	int wt=INT_MIN;
	for(int i=1;i<=cnt;i++){
		wt=max(wt,b[i]);
	}
	cout<<wt;
    return 0;
}
