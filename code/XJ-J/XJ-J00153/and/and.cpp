#include<bits/stdc++.h>
using namespace std;
const int MAX_N=200010;
int n,m,a[MAX_N],ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=0;i<m;i++){
		ans=ans&a[i];
//		cout<<"and "<<a[i]<<endl;
	}
	cout<<ans;
	return 0;
}
