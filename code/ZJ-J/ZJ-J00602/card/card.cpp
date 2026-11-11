#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
void number(vector<int> v,int num){
	vector<int> v1;
	v.erase(v.begin(),v.begin()+num);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v1.size();j++){
			if(v1[j]==v[i]){
				v1.erase(v1.begin()+j,v1.end());
			}
		}
		v1.push_back(v[i]);
	}
	for(int i=0;i<v1.size();i++){
		ans[v1[i]-1]++;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<int> v;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		number(v,i);
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
