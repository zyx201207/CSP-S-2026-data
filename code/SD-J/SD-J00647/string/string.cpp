#include<bits/stdc++.h>
using namespace std;
struct node {
	long long len ;
	char ac;
}a[200005];
deque<node>q;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].ac;
		q.push_back(a[i]);
	}
	while(q.size()){
		if(q.size()==1)break;
		if(q.front().ac==q.back().ac){
			if(q.front().len>q.back().len){
				q.front().len-=q.back().len;
				q.pop_back();
			}else if(q.front().len<q.back().len){
				q.back().len-=q.front().len;
				q.pop_front();
			}else{
				q.pop_back();
				q.pop_front();
			}
		}else{
			if(q.front().len>q.back().len){
				q.front().len-=q.back().len;
				ans+=q.back().len;
				q.pop_back();
			}else if(q.front().len<q.back().len){
				q.back().len-=q.front().len;
				ans+=q.front().len;
				q.pop_front();
			}else{
				ans+=q.back().len;
				q.pop_back();
				q.pop_front();
			}
		}
	}
	cout<<ans;
}
