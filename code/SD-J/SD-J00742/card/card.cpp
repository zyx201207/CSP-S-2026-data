#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ip,a[500009],b[300009],l;
vector<long long> v,q;
bool w;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i-1;j++){
			q.push_back(v[j]);
		}
		for(int j=i;j<n;j++){
			for(int k=1;k<q.size();k++){
				if(q.empty()){
					q.push_back(v[j]);
					break;
				}
				if(q[k]==v[j]){
					ip=k;
					w=1;
					break;
				}
			while(q.size()>=ip+1&&w){
				q.pop_back();
			}
			q.push_back(v[j]);
			v.erase(v.begin()+j);
		}
		w=0;
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<q.size();k++){
				if(q[k]==j){
					b[j]++;
				}
			}
		}
		q.clear(); v.clear();
		for(int j=1;j<=n;j++){
			v.push_back(a[j]);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
