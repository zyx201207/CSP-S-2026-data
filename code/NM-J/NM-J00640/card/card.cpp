#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>vec;
	map<int,int>mp;
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		vec.push_back(j);
	}
	
	for(int i=0;i<vec.size();i++){
		if(vec[i]==vec[i+1])vec.erase(vec.begin()+i,vec.begin()+i+1);
		mp[vec[i]]++;
	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=i;j--){
			mp[vec[j]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
} 
