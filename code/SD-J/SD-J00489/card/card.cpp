#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10,mod=998244353;

ll n,m,a[N],vis[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(n<=20000){
		for(int i=1;i<=n;i++){
			vector<int > v;
			for(int j=1;j<=m;j++) vis[j]=0;
			for(int j=i;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<a[j]<<endl;
				if(vis[a[j]]){
//					cout<<"delete "<<a[j]<<endl;
					while(v.size()&&v[v.size()-1]!=a[j]){
//						cout<<v[v.size()-1]<<" ";
						vis[v[v.size()-1]]=0;
						v.pop_back();
					}
//					v.push_back(a[j]);
//					cout<<endl;
				}
				else{
					v.push_back(a[j]);
					vis[a[j]]=1;
				}
			}
//			cout<<"i: "<<i<<endl;
			for(int j=0;j<v.size();j++){
				ans[v[j]]++;
//				cout<<v[j]<<" ";
			}
//			cout<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
