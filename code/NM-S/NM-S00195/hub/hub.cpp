#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int a[N];
vector<int>mp[N];
int dist(int x,int y){
	
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    while(t--){
    	int n,k;
    	int b[N];
    	for(int i=1;i<=n;i++){
    		int v,u;
    		cin >> v >> u; 
    		mp[u].push_back(v);
    		mp[v].push_back(u);
		}
	}
    return 0;
}
//0 2
//5 2
//1 2
//2 3
//3 4
//4 5
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10
