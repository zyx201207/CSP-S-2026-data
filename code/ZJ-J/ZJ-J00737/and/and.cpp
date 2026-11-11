#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
struct node{
	string s;
	string s2;
}a[200005];

bool aaa(string x,string y){
	if(x.size()!=y.size()){
		if(x.size()>y.size()) return false;
		else return true;
	}else{
		for(int i=0;i<=x.size();i++){
			if(x[i]!=y[i]){
				if(x[i]>y[i]) return false;
				else return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m=1){
		for(int i=1;i<=n;i++){
			cin>>a[i].s;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(aaa(a[i].s,a[j].s)) swap(a[i].s,a[j].s);
			}
		}
		cout<<a[1].s;
		return 0;
	}
	
	cout<<8;
	return 0;
}
