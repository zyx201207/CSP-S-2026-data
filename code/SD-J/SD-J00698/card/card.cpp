#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int a[N],t[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	unordered_map<int,int> p;
	for(int i=1;i<=n;i++){
		p.clear();
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		}
		for(int j=i;j<=n;j++){
			if(p.find(a[j])!=p.end()&&a[p[a[j]]]!=-1){
				for(int k=p[a[j]];k<j;k++){
					//if(a[k]!=-1)p.erase(a[k]);
					a[k]=-1;
				}
				//cout<<j<<" "<<p[a[j]]<<"  ";
				//cout<<j<<" "<<l[j]<<" "<<p[a[j]]<<endl;
			}
			p[a[j]]=j;
		}	
		for(int k=i;k<=n;k++){
			if(a[k]!=-1) t[a[k]]++;
		//	if(a[k]!=-1) cout<<a[k]<<' ';
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}

