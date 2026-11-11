#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*10*10*10*10*10+33;

int n,m;
stack<int> a;
long long table[MAXN];
int ans[MAXN];
int hsh[MAXN];
int jishu[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		hsh[i]=l;
	}
	int o=n;
	while(o--){
		for(int i=n;i>=1;i--){
			a.push(hsh[i]);
		}
		int i=1;
		int curcard=a.top();
		a.pop();
		
		for(int j=1;j<=i;j++){
			
			if(table[i]==curcard){
				for(int k=1;k<=j;k++){
					table[k]=0;
				}
			}
			else table[++i]=curcard;
		}
		for(int j=1;j<=n;j++){
			if(!table[j])
			jishu[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<jishu[i]<<" ";
	}
	return 0;
}
