#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],maxn=-1145141919810,minn=1145141919810;
void solve4(){
	priority_queue<int,vector<int>,greater<int> > pq;
	int anss=-114,v,cnt,k=0;
	for(int tag=minn;tag<=maxn;tag++){
		while(pq.size()) pq.pop();
		for(int i=1;i<=n;i++){
			if(a[i]<=tag){
				pq.push(tag-a[i]);
			}
		}
		
		v=0;
		cnt=0;
		
		if(pq.size()==n) k++;
		while(pq.size()){
			int t=pq.top();
			pq.pop();
			if(v+t<=m){
				v+=t;
				cnt++;
			}
		}
		anss=max(anss,cnt);
		if(k) break;
	}
	cout<<anss<<endl;
}
void solve5(){
	priority_queue<int,vector<int>,greater<int> > pq;
	int anss=-114,v,cnt,k=0,kr=0,vpre;
	for(int tag=minn;tag<=maxn;tag++){
		while(pq.size()) pq.pop();
		for(int i=1;i<=n;i++){
			if(a[i]<=tag){
				pq.push(tag-a[i]);
			}
		}
		
		v=0;
		cnt=0;
		
		if(pq.size()==n) k++;
		while(pq.size()){
			int t=pq.top();
			pq.pop();
			if(v+t<=m){
				v+=t;
				cnt++;
			}
		}
		
		anss=max(anss,cnt);
		if(vpre==v) kr++;
		else{
			kr=0;
			vpre=v;
		}
		if(kr>=10) break;
		if(k) break;
	}
	cout<<anss<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=20) solve4();
	else solve5();
	fclose(stdin);fclose(stdout);
	return 0;
}
