#include<bits/stdc++.h>
using namespace std;
#define int long long
int l=0;
struct node{
	int a;
	char b;
};
node s[200010];
queue<node> q1;
queue<node> q2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		l+=s[i].a;
	}
	int cnt=0;
	for(int i=1;;i++){
		if(cnt+s[i].a>=l/2){
			q1.push({l/2-cnt,s[i].b});
			break;
		}else{
			q1.push({s[i].a,s[i].b});
			cnt+=s[i].a;
		}
	}
	cnt=l+1;
	for(int i=n;;i--){
		if(cnt-s[i].a<=ceil(double(l)/2)+1){
			q2.push({cnt-(ceil(double(l)/2)+1),s[i].b});
			break;
		}else{
			q2.push({s[i].a,s[i].b});
			cnt-=s[i].a;
		}
	}
//	while(!q1.empty()){
//		cout<<q1.front().a<<','<<q1.front().b<<"  ";
//		q1.pop();
//	}
//	cout<<endl;
//	while(!q2.empty()){
//		cout<<q2.front().a<<','<<q2.front().b<<"  ";
//		q2.pop();
//	}
//	cout<<endl;
	int ans=0;
	while((!q1.empty())&&(!q2.empty())){
		if(q1.front().b!=q2.front().b){
			ans+=min(q1.front().a,q2.front().a);
		}
		if(q1.front().a>q2.front().a){
			q1.front().a-=q2.front().a;
			q2.pop();
		}else if(q1.front().a<q2.front().a){
			q2.front().a-=q1.front().a;
			q1.pop();
		}else{
			q1.pop();q2.pop();
		}
	}
	cout<<ans;
	return 0;
} 
