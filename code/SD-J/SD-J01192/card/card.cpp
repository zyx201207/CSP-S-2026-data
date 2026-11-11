#include <bits/stdc++.h>
using namespace std;

bool t[300000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out", "w",stdout);
	map<int,int> ret;
	int n,m;
	cin>>n>>m;
	vector<int> arr;
	
	arr.push_back(0);
	for(int i = 0; i < n; i++){
		int t;
		cin>>t;
		arr.push_back(t);
	}
	for(int ik = 1; ik <= n; ik++){
		queue<int> q;
		map<int,bool> mm;
		for(int i = ik; i <= n; i++){
			if(!mm[arr[i]]){
				q.push(arr[i]);
				mm[arr[i]]=1;
			}
			else{
				int flag = q.front();
				while(q.front()!=arr[i]){
					q.push(q.front());
					q.pop();
				}
				q.pop();
				while(q.front()!=flag&&!q.empty()){
					mm[q.front()]=0;
					q.pop();
				}
				q.push(arr[i]);
			}
		}
		for(int i = 1; i <= m; i++){
			if(mm[i]==1){
				ret[i]=ret[i]+1;
			}
		}
//		while(q.size()!=0){
//			cout << q.front() << ' '; 
//			q.pop();
//		} 
//		cout << endl;
	}
	for(int i = 1; i <= m; i++){
		cout << ret[i] << ' ';
	}
	return 0;
} 
