#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n;
struct node{
	LL num;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	LL ans=0;
	for(int i=1,j=n;i<=n,j>=1;){
		if(i==j)break;
		if(a[i].num>a[j].num){
			if(a[i].c!=a[j].c)ans+=a[j].num;
			a[i].num-=a[j].num;
			j--;
		}
		else{
			if(a[i].c!=a[j].c)ans+=a[i].num;
			a[j].num-=a[i].num;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
