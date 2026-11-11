#include<bits/stdc++.h>
using namespace std;
int n,m,a[200500];
long long s;
bool b[200500][31],dk[200500];
signed main(){
  freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++)b[i][j]=(a[i]>>j)&1;
	}
	for(int i=30;i>=0;i--){
		vector<int>v;
		int rs=0;
		for(int j=1;j<=n;j++)
			if(!dk[j]){
				v.push_back(j);
				if(b[j][i])rs++;
			}
		if(rs<m)continue;
		s+=(1<<i);
		for(auto j:v)
			if(!b[j][i])dk[j]=1;
	}
	cout<<s;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/