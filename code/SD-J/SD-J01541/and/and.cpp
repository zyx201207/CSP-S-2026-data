#include<bits/stdc++.h>
using namespace std;
int n,m,la=0;
int num=2097151;
int r[200005]={0};
bool cmd(int a,int b){
	return a>b;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+1+n,cmd);
	for(int i=1;i<=m;i++){
		if(la!=r[i]&&num!=r[i]&&r[i]&r[i+1]!=0&&r[i]/r[i+1]<2){
			cout<<r[i]<<' ';
			num=num&r[i];
			cout<<num;
			la=r[i];
		}
	}
	
	cout<<num;
	return 0;


} 
