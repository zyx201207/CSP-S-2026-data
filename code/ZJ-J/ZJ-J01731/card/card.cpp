#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N=5e5+5;
const int M=3e5+5;
int n,m;
vector<int>a;
vector<int>b;
int vis[M];
map<int,int>ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a.push_back(x);
		b.push_back(x);
		vis[x]=1;
	}
	int i=1;
	int t=n;
	while(t--){
		for(int i=n-t-1;i<n;i++){
			if(vis[b[i]]){
				int sum=0;
				for(int j=0;j<n;j++){
					if(a[j]!=b[i]){
						sum++;
					}else{
						for(int k=sum+1;k<n;k++){
							a.pop_back();
						}
						n=sum;
						a.push_back(b[i]);
						break;
					}
					vis[b[i]]=0;
				}
			}else{
				a.push_back(b[i]);
				vis[b[i]]=1;
				n++;
			}
		}
		for(int i=1;i<=n;i++)ans[a[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
