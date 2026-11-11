#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	queue<int> q;
	cin >> n >> m;
	int a[500005]={};
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int j=0;j<n;j++){
		for(int i=j;i<n;i++){
			if(!q.empty()&&q.front()==a[i]){
				while(!q.empty()){
					q.pop();
				}
				q.push(a[i]);
			}else{
				q.push(a[i]);
			}
		}
		for(int i=0;i<int(q.size());i++){
			
	}
	return 0;
}
