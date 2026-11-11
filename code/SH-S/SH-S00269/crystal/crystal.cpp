#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cost(int x){
	int answer=0;
	for(int i=1;i<x;i++){
		answer+=a[x]-a[i];
	}
	return answer;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int next,left=1,right=n;
	while(true){
		next=(left+right)/2;
		int c1=cost(next),c2=cost(next+1);
		if(c1<=m && c2>m){
			cout<<next<<endl;
			break;
		}
		else if(c2<=m){
			left=next+1;
		}
		else{
			right=next-1;
		}
	}
	return 0;
}
