#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],mm[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	queue<int> q;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int i=1;i<=n;i++){
		
		while(!q.empty()){
			if(q.front()==1)  mm[1]++;
			else if(q.front()==2)   mm[2]++;
			q.pop();
		}
		q.push(i);
		
	}
	cout<<mm[1]<<" "<<mm[2];
	return 0;
}