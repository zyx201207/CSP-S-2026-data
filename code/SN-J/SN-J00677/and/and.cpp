//相博然 西安辅轮中学 SN-J00677
#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005];
long long k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]>k) k=a[i];
	}
	
    cout<<k;
	return 0;
}
