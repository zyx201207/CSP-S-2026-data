#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e5+7;
int n,m;
bool z=1;
int a[maxn],cont[maxn];
map<int, int>mp;
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]<a[i-1])z=0; 
	}
	if(z){
		for(int i=1;i<=n;i++) {
			if(a[i]!=a[i+1])cont[a[i]]+=i;
		}
		for(int i=1;i<=m;i++) cout<<cont[i]<<' '; 
	}
	else{
		for(int i=1;i<=n;i++){
			mp.clear();
			for(int j=i;j<=n;j++){
				if(!mp[a[j]]){
					mp[a[j]]=j;
					q.push(a[j]);
				}else{
					while(!q.empty()&&q.top()!=a[j]){
						mp[q.top()]=0;
						q.pop();
					}
					mp[a[j]]=j;
				}
			}
			while(!q.empty()){
				cont[q.top()]++;
				q.pop();
			}
		}
		for(int i=1;i<=m;i++) cout<<cont[i]<<' ';
	} 
	return 0;
} 
/*

10 3
3 1 2 1 3 2 3 1 2 1
6 4
11111
1 1 2 3 3 4
*/
