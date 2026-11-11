#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int a,b,t[600000],w[600000];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>t[i];
	}
	int y=a;
	while(a--){
		q.push(t[y-a+1]);
		for(int i=y-a+1;i<=a;i++){
			q.push(t[i]);
			if(t[i]==q.front()){
				q.pop();
				while(q.front()!=t[i]){
					q.pop();
				}
			}
		}
		while(!q.empty()){
			w[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=b;i++){
		cout<<w[i]<<" ";
	}
	return 0;
}
