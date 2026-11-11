#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int u[100010];
vector<int>v;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(a,1e9,sizeof a);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		//cout<<i<<"---\n";
		for(int j=1;j<i;j++){
			v.push_back(a[j]);
		}
		
		int k=upper_bound(v.begin(),v.end(),a[i])-v.begin()-1;
		//cout<<k<<"\n";
		if(k!=-1&&v[k]==a[i]){
			for(int j=0;j<k;j++){
				u[v[j]]++;
			}
			u[a[i]]++;
		}else{
			for(int j=0;j<v.size();j++){
				u[v[j]]++;
			}
			u[a[i]]++;
		}
		v.clear();
	}
	//cout<<m<<"\n";
	for(int i=1;i<=m;i++){
		cout<<n<<' ';
	}
	return 0;
} 
