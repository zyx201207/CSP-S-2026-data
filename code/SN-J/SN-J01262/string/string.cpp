#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,cnt;
struct node{
	int x;
	char c;
};
deque<node> q;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=0;
	for(int i=1;i<=n;i++){
		int l;
		char h;
		cin>>l>>h;
		r+=l;
		q.push_back({l,h});
	}
	while(q.size()!=0){
		node f=q.front();
		q.pop_front();
		if(q.size()!=0){
			node b=q.back();
			q.pop_back();
			int longer=min(f.x,b.x);
			f.x-=longer;
			b.x-=longer;
			if(f.c==b.c){
				if(b.x!=0) q.push_back(b);
				if(f.x!=0) q.push_front(f);
			}else{
				cnt+=longer;
				if(b.x!=0) q.push_back(b);
				if(f.x!=0) q.push_front(f); 
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
