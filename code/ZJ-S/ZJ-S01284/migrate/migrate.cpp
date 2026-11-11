#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int n;
ll d,a[N];
int ds=1e9,rs=0;
int GetDs(int l,int r){
	int ptr=l,res=0,lptr=0;
	while(ptr<r){
		ptr=lower_bound(a+l,a+r,a[ptr]+d)-a,res++;
		if(ptr==lptr)return -1;
		lptr=ptr;
	}
	return res;
}
void Check(int c,int now,int r,int dis){
//	cout<<now<<"\n";
	if(rs>2||ds==-1)return ;
	if(now==r&&dis==ds)rs++;
	for(int i=now+1;i<=r;i++){
		if(a[i]-a[now]<=d)Check(c,i,r,dis+1);
		else break;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		ll sum=0;
		for(int l=1;l<n;l++){
			for(int r=l+1;r<=n;r++){
				ds=GetDs(l,r),rs=0,Check(c,l,r,0);
//				cout<<ds<<" "<<rs<<"\n";
				if(rs==2)sum++;
//				cout<<"\n";
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/