#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N],b[N];
vector<int> v;
int n,m;
int find(int val){
	int len=v.size();
	for(int i=0;i<len;i++){
		if(v[i]==val){
			return i;
		}
	}
	return -1;
}
map<int,int>mp;
void kill(int i){
	for(int j=i;j<v.size();j++){
		v[j]=-1;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memcpy(b,a,sizeof a);
		v.clear();
		for(int j=i;j<=n;j++){
			if(find(b[j])!=-1){
				kill(find(b[j]));
			}
			v.push_back(b[j]);
		}
		for(int j=0;j<v.size();j++){
			if(v[j]!=-1) mp[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
