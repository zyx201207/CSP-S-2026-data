#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,vis[40],ans;
struct node{
	int a;
	vector<int>v;
	node(int x):a(x){}
	void getv(){
		for(int t=30;t>=0;t--)
			if(a&(1<<t)&&vis[t]>=m)
				v.push_back(t);
	}
};
vector<node>vec;
bool cmp(const node&v1,const node&v2){
	for(int i=0,j=0;i<v1.v.size()&&j<v2.v.size();i++,j++)
		if(v1.v[i]!=v2.v[j])
			return v1.v[i]>v2.v[j];
	return v1.v.size()>v2.v.size();
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,a,t;i<=n;i++){
		cin>>a;
		vec.push_back(a);
		for(t=30;t>=0;t--)
			if(a&(1<<t))
				vis[t]++;
	}
	for(int i=0;i<n;i++)vec[i].getv();
	sort(vec.begin(),vec.end(),cmp);
	ans=vec[0].a;
	for(int i=1;i<m;i++)ans&=vec[i].a;
	cout<<ans<<"\n";
	return 0;
}