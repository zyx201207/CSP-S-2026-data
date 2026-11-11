#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
int t[200005];
int n,m;
ll maximum=-1;
void dfs(int step,int x){
	if(step==n+1){
		if(x<m+1){
			return;
		}
		ll op=0xffffffffff;
	    for(int i=1;i<=n;i++){
	    	if(t[i]==1){
	    		op=op&a[i];
			} 
	    }
	    maximum=max(maximum,op);
	    return;
	}
	t[step]=0;
	dfs(step+1,x);
	t[step]=1;
	dfs(step+1,x+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		ll maxn=-1;
		ll op;
		for(int i=1;i<=n-1;i++){
			op=a[i]&a[i+1];
			maxn=max(maxn,op);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		ll op=a[1]&a[2];
	    for(int i=3;i<=n;i++){
		    op=op&a[i];
	    }
	    cout<<op;
	    return 0;
	}
	if(m==n-1){
		ll maxn=-1;
		for(int i=1;i<=n;i++){
			ll op=a[1];
			if(i==1) op=a[2];
			for(int j=2;j<=n;j++){
				if(j==i) continue;
				op=op&a[i];
			}
			maxn=max(maxn,op);
		}
		cout<<maxn;
		return 0;
	}
	dfs(1,1);
	cout<<maximum;
	return 0;
} 
