#include<bits/stdc++.h>
using namespace std;
string s;
vector<int > v;
int n,m,a[500100],cnt[500005];
int main(){
//	ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	
		
	
		
		
	}
	int l=1;
	while(l<=n){
		for(int i=l;i<=n;i++){
			int id=-1;
			for(int j=0;j<v.size();j++){
				if(v[j]==a[i])  id=j;
				
			}
			if(id!=-1){
				
				v.erase(v.begin()+id,v.end());
			}
			v.push_back(a[i]);
		}
		for(int i=0;i<v.size();i++){
			
			cnt[v[i]]++;
		}
	
		l++;
		v.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
