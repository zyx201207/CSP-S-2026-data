#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n,b[200005],t,m,c[200005],a[200005],ttt=(1<<30)-1;
string d[200005];
vector<int>v,vv;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(i);
		
	}
	for(int i=30;i>=1;i--){
		vv.clear();
		for(int j=0;j<v.size();j++){
			if((a[v[j]]&(1<<(i-1)))!=0){
				vv.push_back(v[j]);
				
			}
		}
		if(vv.size()<m){
			
			continue;
		}
		v.clear();
		for(int j=0;j<vv.size();j++){
			v.push_back(vv[j]);
		}
	}
	for(int i=0;i<v.size();i++){
		ttt=ttt&(a[v[i]]);
	}
	cout<<ttt;
} 
