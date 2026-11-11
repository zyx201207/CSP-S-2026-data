#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long a[200010];
long long n,m;
long long anst=0;

void dfs(long long k,long long v,int t){
    //cout<<k<<" "<<v<<" "<<t<<endl;
	if(k>n){
		if(t==m){
			anst=max(anst,v);
			//cout<<v<<endl;
		}
		return;
	}
	dfs(1+k,v,t);
	long long tmp;
	if(v==-1)
        tmp=a[k];
	else{
        tmp=v;
        tmp&=a[k];
	}
	dfs(1+k,tmp,t+1);
	return;
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    //cout<<"ok";
    if(m==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
	    //cout<<"ok";
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
				    long long tmp=a[i];
				    tmp &= a[j];
				    ans=max(ans,tmp);
				}
			}
		}
		cout<<ans;
	}else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans &= a[i];
		}
		cout<<ans;
	}else{
		dfs(0,-1,0);
		cout<<anst;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
