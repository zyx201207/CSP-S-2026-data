#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],visa[300005],visb[300005];
int d[500005];
int r=1;
void push(int x){
	d[r++]=x;
}
int top(){
	return d[r-1];
}
void pop(){
	r--;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(visa[a[i]]==0){
			visa[a[i]]=i;
		}
		push(a[i]);
		if(visb[a[i]]==1){
			int rr=1;
			pop();
			while(top()!=a[i]){
				visa[top()]--;rr++;
				pop();
			}
			r+=rr;
		}else{
			visb[a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<visa[i]<<" ";
	}
	return 0;
}
