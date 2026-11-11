#include<bits/stdc++.h>
using namespace std;
long long n,m,ma=LONG_LONG_MIN,temp=0, k[200003];
bool flag=false;
bool used[200003],no[200003];
void dfs(int times,int tl){
	if(times==m+1){
		ma=max(temp,ma);
		temp=tl;
//		cout<<endl;
		return ;
	}
	for(int i=1;i<=n ;i++){
		if(used[i] || no[i]) continue;
//		cout<<k[i]<<" ";
		int ks=temp;
		if(times!=1) temp&=k[i];
		cout<<temp<<endl;
		used[i]=true;
		dfs(times+1,ks);
		used[i]=false;
		if(times==1) no[i]=true;
	}
}
int main(){
    freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	dfs(1,1);
	printf("%lld",ma);
    fclose(stdin);
   fclose(stdout);
    return 0;
}
