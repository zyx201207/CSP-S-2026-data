#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M=200005;
int n,l,num,ans;

struct qjj{
	int a;
	char c;
}q[M];
stack<qjj>s1;
stack<qjj>s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].c;
		l+=q[i].a;
	}
	int cnt;
	if(l%2==1){
		cnt=1;
	}else cnt=0;
	l/=2;
	int i=1,sum;
	bool vis=0;
	while(num<l&&i<=n){
		if((num+q[i].a)<l){
			num+=q[i].a;
			s1.push({q[i].a,q[i].c});
		}else if((num+q[i].a)==l){
				num+=q[i].a;
				s1.push({q[i].a,q[i].c});
				sum=i+1;
		}else{
			int k=l-num;
			num=l;
			s1.push({k,q[i].c});
			sum=i;
			q[i].a-=(k+cnt);	
		}
		i++;
	}
	num=0;
	for(int i=n;i>=sum;i--){
		if(num+q[i].a<=l){
			num+=q[i].a;
			s2.push({q[i].a,q[i].c});
		}else {
			int k=l-num;
			num=l;			
			s2.push({k,q[i].c});
		}

	}
	while(!s1.empty()||!s2.empty()){
		qjj q1=s1.top(),q2=s2.top();
		s1.pop();s2.pop();
		int lr=0;
		if(q1.a>q2.a){
			lr=-1;
		}else if(q1.a<q2.a){
			lr=1;
		}
		if(q1.c!=q2.c){			
			if(lr==1){
				ans+=q1.a;
				q2.a-=q1.a;
				s2.push(q2);
			}else if(lr==-1){
				ans+=q2.a;
				q1.a-=q2.a;
				s1.push(q1);				
			}else ans+=q1.a;
		}else {
			if(lr==1){	
				q2.a-=q1.a;
				s2.push(q2);
			}else if(lr==-1){				
				q1.a-=q2.a;
				s1.push(q1);				
			}			
		}
	}
	printf("%lld",ans);
	return 0;
}