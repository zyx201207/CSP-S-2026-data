#include<bits/stdc++.h>
using namespace std;
struct p{
	int f;
	int s;
};
bool cmp(p x,p y){
	return x.s>y.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m=0,n=0;
	cin>>n>>m;
	vector<p> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].f;
		int b=a[i].f;
		while(b!=0){
			int c=b%2;
			b/=2;
			if(c==1)a[i].s++;
		}
	}
	sort(a.begin(),a.end(),cmp);
	int z=a[0].f;
	for(int i=1;i<m;i++){
		int z=a[i].f | z;
	}
	cout<<z;
	return 0 ;
}
