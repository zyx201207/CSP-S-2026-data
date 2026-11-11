#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector <int> tr;
int main(){
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(tr,0,sizeof(tr));
		int n;
		cin>>n;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			tr[u].push_back(v)
		}
	}
	return 0;
}
