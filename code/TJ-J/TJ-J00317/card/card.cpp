#include<bits/stdc++.h>
using namespace std;
int mk[500005],mk2[500005];
int main(){
	for(int i = 0;i<=500005;i++){
		mk[i] = 0;
		mk2[i] = 0;
	} 
	queue<unsigned int> q;
	int n,m;cin>>n>>m;
	for(int j = 1;j<=n;j++){
		for(int i = j;i<=n;i++){
			int x;
			cin>>x;
			q.push(x);
			if(mk[x] == 0){
				mk[x]++;
			}else{
				while(q.top!=x){
					x = q.pop()
				} 
			}
		}
	}
} 
