#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+200;
int n,m;
int a[N];
int aans=INT_MIN;
void search(int p,int k,int id){
	if(k>=m){
		cout<<p<<endl;
		aans=max(aans,p);
	    return;	
	}
	for(int i=id+1;i<=n;i++){
		cout<<p<<" "<<a[i]<<" "<<(p & a[i])<<endl;
		search(p & a[i],k+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) search(a[i],1,i);
	cout<<aans;
	return 0;
}
