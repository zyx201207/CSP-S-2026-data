#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N],b[N];
queue<int> cd;
void zd(int x){
	queue<int> q;
	while(!cd.empty()){
		if(cd.front()==x){
			break;
		}
		q.push(cd.front());
		cd.pop();
	}
	while(!cd.empty()){
		cd.pop();
	}
	while(!q.empty()){
		cd.push(q.front());
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			zd(a[j]);
			cd.push(a[j]);
		}
		while(!cd.empty()){
			b[cd.front()]++;
			cd.pop();
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

