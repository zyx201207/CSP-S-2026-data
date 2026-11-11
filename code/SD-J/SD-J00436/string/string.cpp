#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	vector<pair<long long,char>> v;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	int j=n-1,i=0;
	unsigned long long ans=0;
	while(j>i){
		if(v[i].second!=v[j].second){
			if(v[i].first<v[j].first){
				i++;
				v[j].first-=v[i].first;
				ans+=v[i].first;
			}
			else if(v[i].first==v[j].first){
				ans+=v[i].first;
				i++;
				j--;
			}
			else{
				j--;
				v[i].first-=v[j].first;
				ans+=v[j].first;
			}
		}
		else{
			if(v[i].first<v[j].first){
				i++;
				v[j].first-=v[i].first;
				
			}
			else if(v[i].first==v[j].first){
				
				i++;
				j--;
			}
			else{
				j--;
				v[i].first-=v[j].first;
				
			}
		}
	}
	
	
	

	cout<<ans;
	return 0;
}
