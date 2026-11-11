//t 2026-10-31 10:09
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+5;
int n,m,a[5*N];
bool num[3*N];
int nn[3*N];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;//shuliang zhonglei
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(num,0,sizeof(num));
		int t=i;
		for(int j=i;j<=n;j++){
			q.push(a[j]);
			if(num[a[j]]==0){//wei biaoji
				num[a[j]]=1;
			}else{
				for(int k=t;k<=j-1;k++){
					int x=q.front();
					if(!q.empty()) q.pop();
					num[x]=0;
					//cout<<i<<" "<<j<<' '<<x<<endl;
				}
				t=j;
				num[a[j]]=1;
			}
		}
		//cout<<"-----------"<<endl;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			//cout<<t<<endl;
			nn[t]++;
		}
		//cout<<"-----------"<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<nn[i]<<' ';
	}
	return 0;
}
/*
 * 1 2 1 3 4 3
 * 
10 3
3 1 2 1 3 2 3 1 2 1
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */
