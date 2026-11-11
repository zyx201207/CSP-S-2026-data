#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct node{
	int u,v;
}T[N];
int d;
void dj(int x,int y){
     priority_queue<int ,vector<int>,greater<int> > pq;
     
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>T[i].u>>T[i].v;
		}
		dj(1,n);
		cout<<d; 
	}
	return 0;
} 
