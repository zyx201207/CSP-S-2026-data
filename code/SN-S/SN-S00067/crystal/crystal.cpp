#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	vector<int>v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<m;i++){
		sort(v.begin(),v.end());
		v[0]++;
	}
	for(int i=0;i<n;i++){
		if(v[i]==v[0]){
			cnt++;
		}else{
			break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

