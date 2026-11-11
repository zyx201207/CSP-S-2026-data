#include<bits/stdc++.h>
using namespace std;
int n,m,c,b[100005],a[100005],ans;
bool cmp(int a1,int a2){
	return a1>a2;
}
int f2(){
	int sum=INT_MAX;
	for(int i=1;i<=n;i++){
		if(b[i]){
			sum=(sum&a[i]);
		}
	}
	return sum;
}
void f(int x){
	if(x==m){
		ans=max(f2(),ans);
		return;
	}
	b[x]=0;
	f(x+1);
	b[x]=1;
	f(x+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) c=1;
	}
	if(!c){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	f(0);
	cout<<ans;
	return 0;
}