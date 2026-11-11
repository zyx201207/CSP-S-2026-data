#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,m;
struct node{
	long long ans,id;
}a[N]={0};
bool sort1(node u,node v){
	return u.id<v.id;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int k;
	for(int i=1;i<=n;++i){
		cin>>a[i].id;
		if(a[i].id>a[i-1].id)k++;
	}
	if(k>=n-1){
		a[1].ans=0;
		for(int i=2;i<=n;++i){
			a[i].ans=a[i].id-a[i-1].id+a[i-1].ans;
			if(m-a[i].ans==0){
				cout<<i<<"\n";return 0;
			}
			else if(m-a[i].ans<0){
				cout<<i-1<<"\n";return 0;
			}
		}
		return 0;
	}
	sort(a+1,a+n+1,sort1);
	a[1].ans=0;
	for(int i=2;i<=n;++i){
		a[i].ans=a[i].id-a[i-1].id+a[i-1].ans;
		if(m-a[i].ans==0){
			cout<<i<<"\n";return 0;
		}
		else if(m-a[i].ans<0){
			cout<<i-1<<"\n";return 0;
		}
	}
	return 0;
}
