#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
constexpr int M=3e5+5;
int n,m,ans;
int a[N],cnt[M];
bool used[M];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<=500&&m<=300){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)used[j]=false;
			for(int j=i;j<=n;++j){
//				cout<<a[j]<<" ";
				if(used[a[j]]){
					while(true){
						if(q.front()==a[j])break;
						used[q.front()]=false;
						q.pop();
//						cout<<"del ";
					}
//					cout<<"del ";
				}
				else{
					q.push(a[j]);
					used[a[j]]=true;
				}
			}
//			cout<<"\n";
			while(!q.empty()){
//				cout<<q.front()<<" ";
				++cnt[q.front()];
				q.pop();
			}
//			cout<<"\n";
		}
		for(int i=1;i<=m;++i)cout<<cnt[i]<<" ";
	}//24
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

一年比一年差，我要AFO了

*/