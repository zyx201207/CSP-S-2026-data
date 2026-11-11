//20261031-cspj-00547-t3
#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0;
unsigned int a[200005];
bool cho[200005];
int cnt = 0;
void dfs(int step){
	//cout<<"step"<<step<<",cnt:"<<cnt<<"a:"<<a[step]<<"cho:"<<cho[step]<<'\n';
	if(cnt>=m||step>=n){
		if(cnt!=m){
			return;
		}
	    unsigned int minn =20000000;
	    bool flag = false;
		for(int i =0;i<=n;i++){
			if(cho[i]){
				flag = true;
				if(a[i]<minn){
					//cout<<a[i]<<' ';
					minn=a[i];
				}
			}
			
		}
		//cout<<'\n';
		//cout<<minn<<'\n';
		if(minn > maxn&&flag){
			maxn = minn; 
		}
		return;
	}
	for(int i =0;i<2;i++){
		cnt+=i;
		cho[step] = i;
		dfs(step+1);
		cnt-=i;
	}
}
int main(){
	//redirect
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//LETSGOOOOOOOOOOO
	//不不不不不我无疑是有实力的 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<maxn;
	return 0;
}
