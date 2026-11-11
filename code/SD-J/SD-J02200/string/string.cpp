#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Node{
	LL num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i].num>>a[i].c;
	LL ans=0;
	for (int i=1,j=n;i<j;){
		if (a[i].num>a[j].num){
			if (a[i].c!=a[j].c) ans+=a[j].num;
			a[i].num-=a[j].num;
			j--;
		}
		if (a[i].num==a[j].num){
			if (a[i].c!=a[j].c) ans+=a[i].num;
			i++,j--;
		}
		if (a[i].num<a[j].num){
			if (a[i].c!=a[j].c) ans+=a[i].num;
			a[j].num-=a[i].num;
			i++;
		}
	}
	cout<<ans;
	return 0;
}

