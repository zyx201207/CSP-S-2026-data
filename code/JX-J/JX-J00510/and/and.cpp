#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
int f(int x,int y){
	bool xx[21];
	int aa=x,bb=y,i=0,sum=0,power=1;
	while(aa&&bb){
		xx[i]=(aa%2)&&(bb%2);
		aa/=2;
		bb/=2;
		i++;
	}
	for(int k=0;k<i;k++){
		sum+=xx[k]*power;
		power*=2;
	}
	return sum;
}
void dfs(int w,int st,int v){
	if(st==m){
		ans=max(ans,v);
	}
	for(int i=w+1;i<n;i++){
		dfs(i,st+1,f(v,a[i]));
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==1){
		int maxx=-1;
		for(int i=0;i<n;i++)maxx=max(maxx,a[i]);
		cout<<maxx;
	}
	else if(m==n){
		for(int i=0;i<n;i++)ans+=f(ans,a[i]);
		cout<<ans;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,f(a[i],a[j]));
			}
		}
		cout<<ans;
	}
	else if(n<=2000){
		dfs(0,1,a[0]);
		cout<<ans;
	}
	else{
		sort(a,a+n);
		cout<<a[n-m+1];
	}
    return 0;
}
