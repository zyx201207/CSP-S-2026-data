#include<bits/stdc++.h>
using namespace std;
long long mid,rt,lt,r,l,n,a[200010],len[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len[i]=len[i-1]+a[i];
	}
	if(len[n]%2==0) l=mid=len[n]/2,r=mid+1;
	else mid=len[n]/2+1,l=mid-1,r=mid+1;
	for(int i=1;i<=n;i++){
		if(len[i]<l&&len[i+1]>=l) lt=i;
		if(len[i]<r&&len[i+1]>=r) rt=i+1;
	}	
	while(lt>0||rt<=n){
		if(c[min(n,rt)]!=c[max(lt+1,(long long)1)]) ans+=min(len[rt]-r+1,l-len[lt]);
		if(l-len[lt]>len[rt]-r+1) l-=len[rt]-r+1,r=len[rt]+1,rt++;
		else if(l-len[lt]==len[rt]-r+1) r=len[rt]+1,rt++,l=len[lt],lt--;
		else r+=l-len[lt],l=len[lt],lt--;
	}
	cout<<ans;
	return 0;
}
/*
12
5 a
3 t
7 y
1 t
3 n
1 t
3 a
1 x
5 n
3 a
9 y
1 t
*/
