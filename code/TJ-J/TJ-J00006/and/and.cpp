#include<bits/stdc++.h>
using namespace std;
long long q,w[300000],e;
long long d;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(int i,int h,int g){
	if(i==q+1&&h==e){
		if(d<g){
			d=g;
		}
		return;
	}else if(i==q+1){
	return;
	}	dfs(i+1,h+1,g&w[i]);
		dfs(i+1,h,g);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>q;
	cin>>e;
	for(int i=1;i<=q;i++){
		cin>>w[i];
	}
	sort(w+1,w+q+1,cmp);
	if(q<20){
	dfs(2,1,w[1]);	
	}
	else{
		int s=w[1];
		for(int i=2;i<=e;i++){
			s&w[i];
		}
		cout<<s;
	}
	cout<<d;
	return 0;
} 
