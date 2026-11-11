//相博然 西安辅轮中学 SN-J00677
#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005];
long long k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(a[n]=='1') cout<<n<<n-1;
	else cout<<n-1<<n;
	return 0;
}
