#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],ans[m+1]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		vector<int> t;
		for(int j=i;j<n;j++){
			if(!t.empty()) for(int k=0;k<t.size();k++){
				if(t[k]==a[j]){
					t.erase(t.begin()+k,t.end());
					break;
				} 
			}
			t.push_back(a[j]);
		}
		for(int j=0;j<t.size();j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
