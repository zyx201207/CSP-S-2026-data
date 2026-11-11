#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=31;
int cnt[N][M],w[M],sum[M],maxn,vis[N],f;
long long z[N];
int n,m;
void change(long long a,int pos){
    int j=1,c[31];
    while(a){
        c[j]=a%2;
        j++;
        a/=2;
    }
    //reverse(c+1,c+j+1);
    for(int i=1;i<j;i++){
    	cnt[pos][i]=c[i];
    	sum[i]+=c[i];
    	//cout<<c[i];
	}
	//cout<<endl;
}
void dfs(int maxn,int flag,int need){
	if(f==1)	return;
	int now=0;
	for(int i=1;i<=n;i++){
		if(cnt[i][maxn]==1&&vis[i]==flag)	vis[i]=1,now++;
		else	vis[i]=0;
	}
	if(now!=need){
		maxn--;
		if(maxn==0){
			f=1;
			return;
		}
		while(w[maxn]!=1){
			maxn--;
			if(maxn==0){
				f=1;
				//cout<<0;
				return;
			}
		}
		if(flag==1){
			if(now>need){
				//cout<<maxn<<" "<<" "<<now-need<<endl;
				dfs(maxn,flag^1,now-need);
			}	
			else	dfs(maxn,flag,need-now);
		}
		else if(flag==0){
			if(now<need){
				dfs(maxn,flag,need-now);
			}	
			else	dfs(maxn,flag^1,now-need);			
		}

	}
	else	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long a;
        cin>>a;
        z[i]=a;
        change(a,i);
    }
	for(int i=1;i<=30;i++){
		if(sum[i]>=m)	w[i]=1,maxn=max(maxn,i);
	} 
	dfs(maxn,0,m);
	int ss;
	for(int i=1;i<=n;i++)	ss+=vis[i];
	int ans=-1;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			if(ans==-1)	ans=z[i];
			else	ans&=z[i]; 
		}
	}
	cout<<ans;
    return 0;
}
//bool check(int maxn,int flag,int need){
//	if(f==1)	return;
//	int now=0;
//	for(int i=1;i<=n;i++){
//		if(cnt[i][maxn]==1)	vis[i]=1,now++;
//		else	vis[i]=0;
//	}
//	if(now!=need){
//		return 0;
//	}
//	else	return -1;
//}
