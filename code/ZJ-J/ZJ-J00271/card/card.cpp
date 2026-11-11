#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],lst[300010],cnt[300010],ans[300010],rnuu[300010];
deque <int> q;
void rnu(int l,int r,int bi){
	while(!q.empty())q.pop_back();
	for(int i=1;i<=m;i++)rnuu[i]=-1;
	for(int i=l;i<=r;i++){
		if(rnuu[a[i]]>=0){
			while(!q.empty()&&q.size()>rnuu[a[i]]){
				rnuu[q.front()]=-1;
				q.pop_front();
			}
		}
			rnuu[a[i]]=q.size();
			q.push_front(a[i]);
		
	}
	while(!q.empty()){
		ans[q.front()]+=bi;
		q.pop_front();
	}
}
void sv1(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++,lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++)rnu(lst[i],n,cnt[i]);
	return ;
}
void sv0(){
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)rnu(i,n,1);
	return ;
}
void sv2(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++,lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		ans[i]=lst[i-1]*cnt[i]+(cnt[i]+1)*cnt[i]/2;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n<=5000)sv0();
	else if(m<=3000) sv1();
	else sv2();
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}