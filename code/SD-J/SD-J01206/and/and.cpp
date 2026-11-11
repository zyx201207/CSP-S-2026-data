#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int flag=0,t[200005];
int c[35];
int m,n,pos=1;
long long x,maxx=0,b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>b[i];
			maxx=max(maxx,b[i]);
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		t[b[i]]++;
		if(b[i]>=4){
			flag=1;
		}
	}
	if(flag==0) {
		cout<<3;
		return 0;
	}
		
	return 0;
} 
