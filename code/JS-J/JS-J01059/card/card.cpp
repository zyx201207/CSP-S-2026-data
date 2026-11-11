#include<iostream>
#include<queue>
using namespace std;
int n=0,m=0;
int num[200005];
int ans[100005];
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>num[i];q.push(num[i]);
	}
	for(int i=1;i<=n;i++){
		queue<int> q1,q2,q3;
		if(i!=1) q.pop();
		q1=q;
		while(!q1.empty()){
			int t=q1.front();
			while(!q2.empty()){
				if(q2.front()!=t) {
					q3.push(q2.front());
					q2.pop();
				}
				else break;
			}
			q2=q3;
			while(!q3.empty()){
				//cout<<q3.front()<<" ";
				q3.pop();
			}
			q2.push(t);q1.pop();
		}
		while(!q2.empty()){
			//cout<<q2.front()<<" ";
			ans[q2.front()]++;
			q2.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
