#include<bits/stdc++.h>
using namespace std;
int n,m;
deque<int>q;
int ans[500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		q.push_back(k);
	}
	deque<int>q1=q;
	stable_sort(q1.begin(),q1.end());
	q1.erase(unique(q1.begin(),q1.end()),q1.end());
	for(int i=0;i<n;i++){
		deque<int>qq=q,nowq;
		while(qq.size()!=i){
			int now=qq[i];
			qq.erase(qq.begin()+i);
			nowq.push_back(now);
			for(int j=0;j<nowq.size();j++){
				if(nowq[j]==now){
					nowq.erase(nowq.begin()+j+1,nowq.end());
					break;
				}
			}
		}
		for(int j=0;j<nowq.size();j++)ans[nowq[j]]++;
	}
	for(int i=0;i<q1.size();i++)cout<<ans[q1[i]]<<" ";
	return 0;
}
