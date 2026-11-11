#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5000+10;
int c,t;
int n,d;
int a[N];
vector<int>v[N];
queue<int>q;
int dd[N],e[N];
void dij(int xxx){
	dd[xxx]=0;
	e[xxx]=1;
	q.push(xxx);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<v[x].size();i++){
			int w=v[x][i];
		
			if(dd[w]>dd[x]+1){
				dd[w]=dd[x]+1;
				e[w]=e[x];
				q.push(w);
			}
			else if(dd[w]==dd[x]+1){
				dd[w]=dd[x]+1;
				e[w]+=e[x];
			}
//			if(n!=4)	cout<<x<<" "<<w<<" "<<e[w]<<" "<<dd[w]<<"\n";
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c<=10){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				v[i].clear();
				for(int j=1;j<=n;j++){
					if(i!=j&&abs(a[i]-a[j])<=d){
						v[i].push_back(j);
					}
				}
			}
			memset(dd,0x3f,sizeof(dd));
			int cnt=0;
			for(int i=1;i<=n;i++){
				dij(i);
				for(int j=1;j<=n;j++){
					if(e[j]==2)cnt++;
//					cout<<e[j]<<" ";
				}
//				cout<<"\n";
				for(int j=1;j<=n;j++){
					dd[j]=dd[0];
					e[j]=0;
				}
			}
			cout<<cnt/2<<"\n";
		}
		else if(c<=12){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int w=a[2]-a[1];
			if(d/w<=1){
				cout<<"0\n";
			}
			else if(d/w>=3){
				cout<<"0\n";
			}
			else{
				cout<<n-3<<"\n";
			}
		}
		else if(c<=14){
//			int cnt=n*(n-1)/2;
//			cin>>n>>d;
//			for(int i=1;i<=n;i++){
//				cin>>a[i];
//			}
//			for(int i=1;i<=n;i++){
//				
//			}
//			for(int j=1;j)
//			cout<<n*(n-1)/2;
		}
	}
	return 0;
}
