#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
int n,m;
int a[N];
int sum,lsum;
int f;
int vis[N];
void dfs(int x,int y,int step){
	if(y==m){

		sum=max(sum,step);
		return ;
	}
	if(x==n+1){
		return ;
	}
	vis[x]=1;
	if(f==0){
		f=1;
		dfs(x+1,y+1,a[x]);
		f=0;
	}else{
		dfs(x+1,y+1,a[x]&step);
	}
	
	vis[x]=0;
	dfs(x+1,y,step);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n<=2000){
		dfs(1,0,0);
		cout<<sum;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}      
    int maxn = -1;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
	}                       
	if(maxn<4){
		int l1=0,l2=0,l3=0;
		for(int i=1;i<=n;i++){
		    if(a[i]==1){
		    	l1++;
			}
			if(a[i]==2){
		    	l2++;
			}
			if(a[i]==3){
		    	l3++;
			}
			if(l3>=m){
				cout<<3;
				return 0;
			}else if(l1+l3>=m){
				cout<<1;
				return 0;
			}else{
				cout<<0<<endl;
			}
	    } 
	}                                                                                                                                                                    
	return 0;
}

