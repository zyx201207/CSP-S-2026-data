#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cnt[500005];
stack<long long> s;
queue<long long> q;
long long n,m;
int main(){
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		q.push(t);
	}
	for(int j=1;j<=n;j++){
		queue<long long> qq=q;
		memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n-j+1;i++){
		int t=qq.front();
		qq.pop();
		if(cnt[t]==0){
			cnt[t]=1;
			s.push(t);
		}else{
			while(!s.empty()){
				if(s.top()==t){
					break;
				}else{
					cnt[s.top()]=0;
					s.pop();
				}
			}
		}
	}
	q.pop();
	while(!s.empty()){
		//cout<<s.top()<<" ";
		a[s.top()]++;
		s.pop();
	}
	//cout<<endl;
}
for(int i=1;i<=m;i++){
	cout<<a[i]<<" ";
}
	return 0;
}
