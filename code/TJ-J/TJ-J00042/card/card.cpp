#include<bits/stdc++.h>
using namespace std;
int n,m,a[500020],ans[500020],c[500020],e[500020],f,nn;
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		/*
		if(i == 0||e[i]!=e[i-1]){
			a[nn] = e[i];
			nn++;
			a[nn] = e[i];
			nn++;
			//ans[e[i]]+=nn;
			//f = 1;
			//cout<<a[nn-1]<<" ";
		}
		else if(e[i]==e[i-1]){
			f++;
		}
		*/
	}
	//cout<<endl<<endl;
	//cout<<nn<<endl;
	
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			if(c[a[j]] == 0){
				c[a[j]]++;
				q.push(a[j]);
			}
			else{
				while(!q.empty()){
					c[q.top()]--;
					if(q.top() == a[j]){
						q.pop();
						break;
					}
					q.pop();
				}
				q.push(a[j]);
				c[a[j]]++;
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			//cout<<q.top()<<" ";
			q.pop();
		}
		//cout<<endl;
		for(int j = 0;j<=m;j++){
			c[j] = 0;
		}
	}
	for(int j = 1;j<=m;j++){
		cout<<ans[j]<<" ";
		//j++;
	}
	return 0;
}
