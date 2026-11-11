#include<bits/stdc++.h>
using namespace std;
int a[500050];
int cnt[300050];
int n,m;
int f[300050];
void sch(int j){
	vector<int>v;
	memset(f,-1,sizeof f);
	for(int i=j;i<n;i++){
		if(f[a[i]]==-1){
			v.push_back(a[i]);
			f[a[i]]=i;
		}
		else{
			v.erase(v.begin()+f[a[i]]+1);
			memset(f,-1,sizeof f);
			for(int k=0;k<v.size();k++){
				f[a[k]]=k;
			}
			f[a[i]]=i;
			v.push_back(a[i]);
		}
	}
	memset(f,0,sizeof f);
	for(auto x:v){
		if(f[x]==0){
			cnt[x]++;
			f[x]=1;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sch(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
