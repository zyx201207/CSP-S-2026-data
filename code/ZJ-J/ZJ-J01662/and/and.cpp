#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans1=0;
struct node{
	int x;
	int y;
}a[1000005];
bool cmp(node b,node c){
	if(b.y!=c.y)return b.y>c.y;
	else return b.x>c.x;
}
int change(int x){
	vector<int> v;
	while(x>0){
		if(x%2==1){
			v.push_back(1);
		}
		else v.push_back(0);
		x/=2;
	}
	int ans=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==1) ans++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
  		int z;
	 	cin>>z;
	 	a[i].x=z;
		a[i].y=change(z);
	}
	sort(a+1,a+n+1,cmp);
	int cnt=a[m].x;
	cout<<cnt;
	return 0;
}
