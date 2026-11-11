#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull ans,c,i,j,l=1,n,r,sum;
struct o{ll num;char ch;}a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i].num>>a[i].ch,sum+=a[i].num;
	i=1,j=n,r=sum;
	while(l<r){
		if(a[i].ch-a[j].ch) ans+=min(a[i].num,a[j].num);
		l+=min(a[i].num,a[j].num),r-=min(a[i].num,a[j].num);
		if(a[i].num>a[j].num) j--;	else i++;
	}
	cout<<ans;	return 0;
}
