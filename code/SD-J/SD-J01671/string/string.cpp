#include <iostream>
#include <stack>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	ll cnt;
	char ch;
}a[N];
int n;
ll sum,ans,k,t;
stack <node> st1;
stack <node> st2;
stack <node> st22;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].ch;
		sum+=a[i].cnt;
	} 
	t=(sum-sum%2)/2;
	for(ll i=1;i<=n;i++){
		if(k+a[i].cnt<=t){
			st1.push({a[i].cnt,a[i].ch});
			k+=a[i].cnt;
		}
		else {
			if(k<=t&&a[i].cnt+k>=t){
				st1.push({t-k,a[i].ch});
				st22.push({a[i].cnt-t-sum%2+k,a[i].ch});
				k+=a[i].cnt;
			}
			else st22.push({a[i].cnt,a[i].ch});
		}
	}
	while(!st22.empty()){
		st2.push(st22.top());
		st22.pop();
	}
	while(!st1.empty()&&!st2.empty()){
		node t1=st1.top(),t2=st2.top();
		st1.pop(),st2.pop();
		if(t1.ch!=t2.ch){
			if(t1.cnt>=t2.cnt){
				t1.cnt-=t2.cnt;
				ans+=t2.cnt;
				st1.push(t1);
			}
			else {
				t2.cnt-=t1.cnt;
				ans+=t1.cnt;
				st2.push(t2);
			}
		}
		else {
			if(t1.cnt>=t2.cnt){
				t1.cnt-=t2.cnt;
				st1.push(t1);
			}
			else {
				t2.cnt-=t1.cnt;
				st2.push(t2);
			}
		}
	}
	cout<<ans;
	return 0;
}
