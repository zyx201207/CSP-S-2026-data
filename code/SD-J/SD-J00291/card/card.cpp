#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m,a[MAXN],c[MAXN]={0},ans[MAXN]={0},f=0;
bool food(int j){
	for(int i=0;i<j;i++){
		if(c[i]==a[j]){
			return 1;
		}
	}
	return 0;
}
bool find(int p,int t){
	for(int i=0;i<t;i++){
		if(c[i]==p) return 1;
	}
	return 0;
}
void clean(){
	for(int i=0;i<n;i++){
		c[i]=0;
	}
}
void clean(int p){
	for(int i=0;i<n;i++){
		if(a[i]==p){
			a[i]=0;
			f=1;
			break;
		}
	}
}
void paixu(){
	int j=0;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			a[j]=a[i];
			j++;
		}
	}
}
int main(){
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int t=n,f=0;
	int y=0;
	for(int i=0;i<n;i++){
		f=0;
		for(int j=0;j<n;j++){
			if(food(j)){
				clean(a[j]);
				y=0;
			}
			if(a[j]==0) break;
			c[y]=a[j];
			y++;
		}
		paixu();
		for(int i=0;i<n;i++){
			cout<<c[i]<<' ';
		}
		cout<<endl;
		for(int i=1;i<=m;i++){
			if(find(i,n)) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
