//SN-J00752 杨济铭 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[200005];
vector<int> a;
vector<vector<int>> ans;
void f(int x,int y){
	if(y>n-x){
		return;
	}
	if(y<0){
		return;
	}
	if(y==0){
		ans.push_back(a);
		return;
	}
	//cout<<x<<" "<<y<<endl;
	f(x+1,y);
	a.push_back(d[x]);
	f(x+1,y-1);
	a.pop_back();
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	f(0,m);
	int res[ans.size()];
	for(int i=0;i<ans.size();i++){
		res[i]=ans[i][0];
		for(int j=1;j<ans[i].size();j++){
			res[i]&=ans[i][j];
		}
		//cout<<res[i]<<" ";
	}
	int max=0;
	for(int i=0;i<ans.size();i++){
		if(max<res[i]){
			max=res[i];
		}
	}
	cout<<max;
	return 0;
}
