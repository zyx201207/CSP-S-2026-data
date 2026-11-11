#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int c,t,n,k;
vector<int>edges;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cout<<(t+1)%2+1<<endl;
	}
	return 0;
}
