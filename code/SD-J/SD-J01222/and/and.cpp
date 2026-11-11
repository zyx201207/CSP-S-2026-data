#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
struct node{
	int number,cha;
}a[200005];
bool cmp(node x,node y){
	if(x.cha==y.cha)return x.number>y.number;
	else return x.cha<y.cha;
} 
signed main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].number;
		if(a[i].number>mx){
			mx=a[i].number;
		}
	} 
	for(int i=1;i<=n;i++){
		int h=mx^a[i].number;
		while(h){
			a[i].cha+=h%2;
			h/=2; 
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=mx;
	for(int i=2;i<=m;i++){
		//cout<<ans<<" "<<a[i].number<<" "<<a[i].cha<<endl;
		ans&=a[i].number;
	}
	
	cout<<ans;
	return 0;
}
