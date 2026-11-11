#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n;
long long ans;
struct emp{
	long long v;
	char c;
};
queue<emp>q1;
queue<emp>q2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int l=0,r=n-1;
	emp p[n];
	for(int i=0;i<n;i++){
		cin>>p[i].v>>p[i].c;
	}
	q1.push(p[0]);
	q2.push(p[n-1]);
	while(l!=n-1){
		long long l1=q1.front().v;
		long long l2=q2.front().v;
		char c1=q1.front().c;
		char c2=q2.front().c;

		if(c1==c2){
			emp a;
			if(l1>l2){
				a.c =c1;
				a.v =l1-l2;
				q1.push(a);
			}else {
				a.c =c2;
				a.v =l2-l1;
				q2.push(a);
			}	
		}else{
			emp a;
			if(l1>l2){
				a.c =c1;
				a.v =l1-l2;
				q1.push(a);
				ans+=l2;
			}else{
				a.c =c2;
				a.v =l2-l1;
				q2.push(a);
				ans+=l1 ;
			}
		}
		q1.pop();
		q2.pop();
		l++,r--;
		q1.push(p[l]);
		q2.push(p[r]); 
	}
	cout<<ans;
	return 0;
}



