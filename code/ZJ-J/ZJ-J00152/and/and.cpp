#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int mas=-1;
map<int,bool> ma;
bool f=1;
int mis=INT_MAX;
map<int,bool> ms; 
bool cmp(int a,int b){
	return a>b;
}
void z(){
	int c=1;
	for(int i=2;i<=20;i++){
		c*=2;
		ma[c-1]=1;
	}
}
void dl(){
	for(int i=1;i<=n;i++){
		if(i==m) {
		cout<<a[i];
		return ;
		}
		
	}
}
void dfs(int dep,int i,int sum){
	if(dep==m){
		mas=max(mas,sum);
		return ;
	}
	if((mas>>1)>=sum||mas>=sum){
		return ;
	}
	for(int j=i+1;j<=n;j++){
		ms[a[i]]=1;
		dfs(dep+1,j,sum&a[j]);
		ms[a[i]]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
z();
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		mas=max(mas,a[i]);
		mis=min(mis,a[i]);
		if(ma[a[i]]!=1){
			f=0;
		}
	}
	if(m==1){
		cout<<mas;
		return 0;	
	}
	mas=-1;
	sort(a+1,a+1+n,cmp);
	if(f){
		dl();
		return 0;
	}
	for(int i=1;i<=n;i++){
        ms[a[i]]=1;
		dfs(1,i,a[i]);
		ms[a[i]]=0;
	}
	cout<<mas;
	return 0;
}
/*
5 2
63 45 54 3 13
*/
