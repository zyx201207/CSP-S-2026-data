#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
string s;
long long a;
char c;
struct node{
	long long cnt;
	char x;
};
deque<node> qu;
long long sum=0;
node t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		t.cnt=a;
		t.x=c;
		qu.push_back(t);
	}
	sum=0;
	while(qu.size()>1){
		node p=qu.front();
		node pp=qu.back();
		qu.pop_front();
		qu.pop_back();
		long long bb;
		if(p.x==pp.x){
			if(p.cnt>pp.cnt){
				bb=p.cnt-pp.cnt;
				t.cnt=bb;
				t.x=p.x;
				qu.push_front(t);
			}
			else if(p.cnt<pp.cnt){
				bb=pp.cnt-p.cnt;
				t.cnt=bb;
				t.x=p.x;
				qu.push_back(t);
			}
		}
		if(p.x!=pp.x){
			if(p.cnt>pp.cnt){
				bb=p.cnt-pp.cnt;
				t.cnt=bb;
				t.x=p.x;
				if(bb!=0)qu.push_front(t);
				sum+=p.cnt-bb;
			}
			else if(p.cnt<pp.cnt){
				bb=pp.cnt-p.cnt;
				t.cnt=bb;
				t.x=pp.x;
				if(bb!=0)qu.push_back(t);
				sum+=pp.cnt-bb;
			}
			else sum+=p.cnt;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
