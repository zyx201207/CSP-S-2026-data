#include<bits/stdc++.h>
using namespace std;
int n,m,a[505050],lsta[500500],hv,as[500500],C[500500],D[500500],E[500500];
struct del{
	int l,r;
};
vector<del>v;
bool b[500500];
signed main(){
  freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		C[a[i]]++;
	}
	for(int h=n;h>0;h--){
		D[h-1]=D[h]+C[a[h]]*(!b[a[h]])-1;
		if(!b[a[h]]){
			if(b[a[h-1]])as[a[h]]=C[a[h]]-E[a[h]];
			else as[a[h]]=h-D[h];
		}
		E[a[h]]++;
		b[a[h]]=1;
	}
	for(int i=1;i<=m;i++)cout<<as[i]<<' ';
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/