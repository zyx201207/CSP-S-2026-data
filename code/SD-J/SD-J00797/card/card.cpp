#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
stack<int> q;
int n,m;
int a[500005],cnt[50000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=0;
	for(int i=1;i<=n;i++){
		while(!q.empty()){
			q.pop();
		}
		for(int i=1;i<=m;i++){
			cnt[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(!mp.empty()){
				if(mp.find(a[j])==mp.end()){
					q.push(a[j]);
					cnt[a[j]]++;
					mp[a[j]]++;
				}else if(mp.find(a[j])!=mp.end()){
					while(q.top()!=a[j]){
						cnt[q.top()]--;
						mp[q.top()]--;
						q.pop();
					}	
				}
			}
		}
		//cout<<cnt[a[i]]<<' ';
		cout<<mp[a[i]];
	}
	return 0;
}
