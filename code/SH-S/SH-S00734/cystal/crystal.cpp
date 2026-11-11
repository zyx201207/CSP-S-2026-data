#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
//unordered_map<int,int>cnt;
//pass pretest at 15:29
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	int sum=0;
	int lst=1,maxx=1;
	for(int i=1;i<=n;i++){
		int now=a[i]*(i-lst)-sum;
		while(now>m&&lst<i){
			now-=a[i]-a[lst++];
			sum-=a[lst-1];
		}
		maxx=max(maxx,i-lst+1);
		sum+=a[i];
	}
	cout<<maxx;
	return 0;
}











// Caution Time: 1516 


















/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a;
unordered_map<int,int>cnt;
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		cnt[tmp]++;
		a.push_back(tmp); 
	}
	sort(a.begin(),a.end());
//	a.erase(unique(a.begin(),a.end()),a.end());
	
	int cur=m;
	int ans=0,maxx=0;
	
	queue<pair<int,int> >q;
	for(int i=1;i<=n;i++){
		int buy=0;
		while(cur-a[i]>0&&buy<cnt[a[i]]){
			cur-=a[i];buy++;
		}
		int ft=0,claim=0;
		if(!q.empty()){
			while(q.front().second==0)q.pop();
			if(q.front().first<i){
				ft=q.front().first;
				claim=q.front().second;
			}
		}
		int tsu=claim*a[ft];int ct2=0;
		while(tsu-a[i]>0&&buy<cnt[a[i]]){
			tsu-=a[i];buy++;ct2++;
		}
		if(!q.empty()){
			q.front().second=claim-ct2;
		}
		
		q.push({i,1});
	}
	
	return 0;
}

*/
