#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
deque<pair<int,char> >dq; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		dq.push_back({a,c});
	}
	int ans=0;
	while(dq.size()>1){
		pair<int,char>p1=dq.front(),p2=dq.back();
		dq.pop_front();
		dq.pop_back();
		if(p1.first<p2.first){
			if(p1.second!=p2.second)ans+=p1.first;
			p2.first-=p1.first;
			p1.first=0;
			dq.push_back(p2);
		}else{
			if(p1.second!=p2.second)ans+=p2.first;
			p1.first-=p2.first;
			p2.first=0;
			if(p1.first)dq.push_front(p1);
		}
	}
	cout<<ans;
	return 0;
}
/*
前面部分看T1
8:50 开T2
8:50 找到关键性质：我们可以每次取队首和队尾的连续段到其中有一个没了，还有这题有点像原，回去用原题机搜一下，如果真的是下次CCF小心点 
8:57 fix:CE，我怎么把双端队列名称dq写成pq了，还把push_back写成push了，我真唐，修了 
9:00 fix:样例4 WA，把一处pair<int,int>改为pair<int,char>，把33行的push_back改为push_front，我真区，修了 
*/
