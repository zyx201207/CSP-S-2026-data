#include<bits/stdc++.h>
using namespace std;
const int N=5e5+55;
int c,n,m,d,q;
int w[N];
int k;
int a[N],t[N];
int f,l;

bool r[N];
int ans=N;
vector<int> a1[N]; 
vector<int> t1[N]; 
void road(int x,int m){
	if(x==l){
		ans=min(ans,m);
		return ;
	}
	for(int i=0;i<a1[x].size();i++){
		
		if(r[a1[x][i]]==1){
			continue;
		}
//		cout<<x<<' '<<a1[x][i]<<' '<<t1[x][i]<<'\n';
		r[a1[x][i]]=1;
		road(a1[x][i],m+t1[x][i]);
		r[a1[x][i]]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int k=1;k<j;k++){
//				cout<<"a"<<a[k]<<' '<<a[j]<<'\n';
				a1[a[k]].push_back(a[j]);
				t1[a[k]].push_back(t[j]+t[k]);
				a1[a[j]].push_back(a[k]);
				t1[a[j]].push_back(t[j]+t[k]);
//				cout<<a1[1][0]<<'b'<<'\n';
			}
		}
	}
	while(q--){
		ans=N;
		cin>>f>>l;
		for(int i=1;i<=n;i++){
			r[i]=0;
		}
		r[f]=1;
		road(f,0);
		cout<<ans+w[f]+w[l]<<'\n';
	}
	return 0;
}





