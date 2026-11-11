//王宁远 西安辅轮中学 SN-J00726
#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("and1.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m,a[100005],sum=a[1];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];	
	}sort(a+1,a+n+1);
	for(int i=2;i<=m;i++){
	    sum=sum&a[i];    	
	}
	cout<<sum;
	
}
