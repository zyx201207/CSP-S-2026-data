#include<bits/stdc++.h>
#include<cstdio>
#include<stack>
using namespace std;
stack<int> c;

bool used[500010]{0};
int car[500100];
int cont[300001]{0};
int m,n;
void bl(int start){
	for(int i=start-1;i<=n;i++){
		if(used[car[i]]){
			while(c.top()=car[i]){
				used[c.top()]=0;
				c.pop();
			}
		}else{
			c.push(car[i]);
			used[car[i]]=1;
		}
	}
	while(!c.empty()){
		int b=c.top();
		cont[b]++;
		c.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out", "w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>car[i];
	}
	for(int i=1;i<=n;i++){
		bl(i);
		for(int i=0;i<=m;i++){
			used[i]=0;
		}
		
	}
		for(int i=1;i<=m;i++){
		cout<<cont[i]<<" ";
	}

	return 0;
}
