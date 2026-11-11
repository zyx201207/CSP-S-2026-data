#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n,m;
int a[N];
int sum[N];
void solve(int num){
	vector<int> lds;
	for(int i=num;i<=n;i++){
		bool ok=false;
		for(auto k:lds){
			if(k==a[i]) ok=true; 
		}
		if(!ok){
			lds.push_back(a[i]);
		} 
		else{
			vector<int> temp;
			temp.clear();
			for(auto k=lds.begin();k<lds.end();k++){
				if(*k==a[i]){
					break;
				} 
				temp.push_back(*k);
			}
			lds.clear();
			for(auto k:temp){
				lds.push_back(k);
			}
			lds.push_back(a[i]);
		}
	}
	for(auto i:lds){
		sum[i]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
