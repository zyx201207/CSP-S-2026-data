#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
};
int n;
long long ans;
deque<node>q; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		q.push_back({a,c});
	}
	node x=q.front(),y=q.back();
	q.pop_front();
	q.pop_back();
	while(!q.empty()){
		if(x.a>y.a){
			if(x.c!=y.c) ans+=y.a;
			x.a-=y.a;
			y=q.back();
			q.pop_back();
		}
		else if(x.a<y.a){
			if(x.c!=y.c) ans+=x.a;
			y.a-=x.a;
			x=q.front();
			q.pop_front();
		}
		else{
			if(x.c!=y.c) ans+=x.a;
			x=q.front();
			q.pop_front();
			y=q.back();
			q.pop_back();
		}
	}
	if(x.a>y.a){
		if(x.c!=y.c){
			ans+=y.a;
		}
	}
	else if(y.a>x.a){
		if(x.c!=y.c){
			ans+=x.a;
		}
	}
	else{
		if(x.c!=y.c){
			ans+=x.a;
		}
	}
	cout<<ans;
	return 0;
}
