#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
const int INF=1e8;
int e[N];
int sum=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=1;i<=n;i++){
		cin>>e[i];
	}
	sort(e+1,e+1+m,cmp);
	int mid=e[n/2];
	for(int i=1;i<=n;i++){
		int del=abs(mid-e[i]);
		q.push(del);
	}
	while(m>=0){
		while(!q.empty()){
			int del=q.top();
            if(del==0) q.pop(),sum++;
            del=q.top();
			q.pop();
			if(m>=del) m-=del,sum++;
			else break;
		}
	}
	cout<<sum;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
