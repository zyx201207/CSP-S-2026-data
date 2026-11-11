#include <bits/stdc++.h> 
#define int long long
#define endl "\n"
using namespace std;
int n,m;
int a[500005],b[300005],v[300005];
deque<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//cout<<"i: "<<i<<" j: "<<j<<endl;
			//cout<<"cmwa[j]: "<<a[j]<<endl;
			if(v[a[j]]==0){
				q.push_back(a[j]);
				v[a[j]]=1;
			}
			else{
			while(q.back()!=a[j]){
				int t=q.back();
				v[t]=0;
				q.pop_back();
			}
			q.pop_back();
				q.push_back(a[j]);
				v[a[j]]=1;	
			}
			/*for(int i=1;i<=n;i++){
				cout<<"v["<<i<<"]= "<<v[i]<<" ";
			}
			cout<<endl;*/
		}
		while(!q.empty()){
			int t=q.back();
			b[t]++;
			q.pop_back();
		}
		memset(v,0,sizeof(v));
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
