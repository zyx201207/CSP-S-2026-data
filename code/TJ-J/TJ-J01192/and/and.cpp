#include<bits/stdc++.h>
using namespace std;
int and(int x,int y){
	vector<int> a;
	int p,q,m=0;
	while(x!=0||y!=0){
		p=x%2;
		q=y%2;
		if(p==q){
			a.push_back(p);
		}else{
			a.push_back(0);
		}
	}
	for(int i=a.size()-1;i>=0;i--){
		m+=a[i];
		m*=2;
	}
	m/=2;
	return m;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	int a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			s=max(s,and(a[i],a[j]));
		}
	}
	cout<<s;
	return 0;
}
