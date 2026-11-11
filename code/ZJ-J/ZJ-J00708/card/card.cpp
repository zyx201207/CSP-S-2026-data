#include<bits/stdc++.h>
using namespace std;
const int mn = 5e5+9;
int n,m;
stack<int>st;
int cnt[mn],ans[mn];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int a;
		bool flag = 1;
		cin >> a;
		cnt[a]++;
		stack<int>q;
		while(st.size()){
			if(st.top()!=a){
				cnt[st.top()]--;
				q.push(st.top());
				//cout << st.top();
				st.pop();
			}
			else{
				flag = 0;
				cnt[st.top()]--;
				st.pop();
				break;
			}
		}
		while(q.size()&&!flag){
			cnt[q.top()]--;
			q.pop();
		}
		while(q.size()&&flag){
			st.push(q.top());
			cnt[q.top()]++;
			q.pop();
		}
		st.push(a);
		while(st.size()){
			q.push(st.top());
			st.pop();
		}
//		while(q.size()){
//			st.push(q.top());
//			cout << q.top() << " ";
//			q.pop();
//		}
		//cout << "\n";
		for(int i=1;i<=m;i++){
			if(cnt[i]>0)ans[i]++;
		}
	}
	//cout << st.size();
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
