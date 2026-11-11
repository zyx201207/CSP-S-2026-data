#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;
void open(string s){
	if(!s.size())return;
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
struct node{
	int x,bit;
};
int n,m;
int a[N],lst[N],ans[N];
vector<int>q;
int main(){
	open("card");
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int now=0;
		fill(lst+1,lst+n+1,-1);
		for(int j=i;j<=n;j++){
			if(lst[a[j]]==-1){
				q.push_back(a[j]);
				lst[a[j]]=++now;
				continue;
			}
			int k=lst[a[j]];
			while(!q.empty()&&q.size()>k){
				lst[q.back()]=-1;
				q.pop_back();
				now--;
			}
			lst[a[j]]=now;
		}
		while(!q.empty()){
			ans[q.back()]++;
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
4 3
1 2 1 3
*/
