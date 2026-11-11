#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Z,T;
	cin>>Z>>T;
	while(T--){
		int n, d;
		cin>>n>>d;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<vector<int>> b;
		for(int i=0;i<n;i++){
			int m=b.size();
			for(int j=0;j<m;j++){
				if(b[j].back()-a[i]<=d||a[i]-b[j].back()<=d){
					auto v=b[j];
					v.push_back(a[i]);
					b.push_back(v);
				}
			}
			b.push_back({a[i]});
		}
		set<vector<int>> out;
		int c[n]={},X=0;
		for(auto &v:b){
			if(v.size()>=2){
				vector<int> x;
				int sum=0;
				for(auto xx:v){
					sum+=x.back()-xx;
					x.push_back(xx);
				}
				c[X]=sum;
				X++;
				out.insert(v);
			}
		}
		X=0;
		for(auto v:out){
			b[X]=v;
			b[X].push_back(c[X]);
		}
		int ans=0;
		for(auto v:b){
			for(auto x:b){
				if(v.back()==x.back()){
					v.pop_back();x.pop_back();
					if(v.back()==x.back()){
					 	if(v.size()!=b.size()){
					 		int i=0,j=0;
					 		for(auto vv:v){
					 			int y=0;
					 			for(auto xx:x){
					 				if(vv!=xx){
					 					y++;
									 }
								}
								if(y==x.size()-2){
									i++;
								}
							}
					 		for(auto vv:x){
					 			int y=0;
					 			for(auto xx:v){
					 				if(vv!=xx){
					 					y++;
									 }
								}
								if(y==v.size()-2){
									j++;
								}
							}
							if(i==0||j==0){
								continue;
							}
						 }
					 	while(v.size()>1){
					 		v.pop_back();
						}
						while(x.size()>1){
							x.pop_back();
						}
						if(v.back()==x.back()){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
