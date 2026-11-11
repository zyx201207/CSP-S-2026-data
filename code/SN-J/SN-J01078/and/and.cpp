#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

bitset<30> s[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		long long x;
		cin >> x;
		s[i]=x;
//		cout << s[i] << "\n";
	}
	
	vector<pair<int,bool>> chos;
	chos.reserve(n);
	
	int high=-1;
	for(int i=29;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(s[j][i]){
				if(high==-1) high=i;
				if(i==high){
					chos.push_back({j,1});
				}
			}
		}
		if(high!=-1){
			if(chos.size()<m){
				chos.clear();
				high=-1;
			}else break;
		}

	}

	
	if(chos.size()<m){
		cout << 0;
		return 0;
	}
	
	int sz=chos.size(),pop=0;
	vector<bool> temp(sz);
	
	bool flag=0;
	for(int i=high-1;i>=0;i--){
		
		for(int i=0;i<chos.size();i++){
			if(!s[chos[i].first][i]){
				temp[i]=1;
				pop++;
			}
//			if(sz-pop<=m) break;
		}
		if(sz-pop==m){
			flag=1;break;
		}else if(sz-pop<m){
			fill(temp.begin(),temp.end(),0);
			pop=0;
		}else{ //sz-pop>m
			for(int i=0;i<sz;i++){
				if(temp[i]) chos[i].second=0,sz--;
			}
			pop=0;
		}
		
	}
	
//	for(int i=0;i<chos.size();i++){
//		if(chos[i].second) cout << chos[i].first << ' ';
//	}
	
//	if(!flag){
//		cout << 0;
//		return 0;
//	}
	
	long long ans=(1<<30)-1;
	bitset<30> ansbit=ans;
	
	for(auto &i:chos){
		if(i.second){
			ansbit &= s[i.first];
//			cout << ansbit << "\n";
		}
	}
	
	ans=0;
	for(int i=29;i>=0;i--){
		if(ansbit[i]) ans+=1<<i;
	}
	
	cout << ans;

	return 0;
}
