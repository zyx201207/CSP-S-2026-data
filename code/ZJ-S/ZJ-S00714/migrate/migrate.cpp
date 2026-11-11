#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000010;
ll a[N],nxt[N];
int n,d;
bool flag[N];
int find(ll id){
	int l=1,r=n,ans=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=id) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cout<<log(2000000);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			flag[i]=false;
		}
		vector<int> x,y;
		for(int i=1;i<=n;i++){
			nxt[i]=find(a[i]+d);
			//cout<<temp<<endl;
			if(!flag[nxt[i]]){
				y.push_back(i);
				x.push_back(nxt[i]);
				flag[nxt[i]]=true;
			}
		}
//		for(int i=0;i<x.size();i++) cout<<x[i]<<' ';
//		cout<<endl;
//		for(int i=0;i<y.size();i++) cout<<y[i]<<" ";
//		cout<<endl;
		int id=1,ans=0;
		int len=x.size();
		for(int i=0;i<x.size()-1;i++){
			while(id<y.size()&&y[id]<x[i]){
				//cout<<y[id]<<' '<<x[i]<<endl;
				if(x[i]-y[id]==1){
					if(id==y.size()-1) ans+=n-x[i];
					else{
						if(nxt[x[i]]==nxt[y[id]]) ans+=nxt[y[id]]-x[i];
						else ans+=x[i+1]-y[id+1];
					}
				}
				id++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
