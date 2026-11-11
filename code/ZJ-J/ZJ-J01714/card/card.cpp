#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r"stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>list(n);
	for(int i=0;i<n;i++){
		cin>>list[i];
	}
	vector<int>ans(m,0);
	for(int ii=0;ii<n;ii++){
		deque<int>desk;
		vector<bool>ap(m,0);
		for(int i=ii;i<n;i++){
			if(ap[list[i]]){
				while(ap[list[i]]){
					int x=desk.back();
					if(x==list[i]){
						ap[list[i]]=0;
					}
					desk.pop_back();
				}
			}
			ap[list[i]]=1;
			desk.push_back(list[i]);
		}
		while(desk.size()>0){
			ans[desk.back()-1]++;
			desk.pop_back();
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
