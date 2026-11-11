//孙瑞泽	SN-J00783	西安市第八十九中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,num[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	ans=num[n-1];
	for(int i=1;i<=m;i++){
		ans=ans&num[n-i];
	}
	cout<<ans;
}
