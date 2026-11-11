#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	//hub
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k,temp;
		cin>>n>>k;
		vector<pair<int,int> >a;
		a.reserve(n);
		while(cin>>temp)a.push_back(temp);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
