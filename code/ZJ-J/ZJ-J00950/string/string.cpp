#include<bits/stdc++.h>
//#define int long long
using namespace std;
/*
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
*/
long long n,len,ans;
const int N=2e5+5;
struct nod{
	int a;
	char b;
}k[N];
char hs(int rp){
	int l=1,r=n,mid=0;
//	cout<<"hs"<<"\n";
	while(l+1<r){
		mid=(l+r)/2;
//		cout<<mid<<"midmid\n";
		if(rp<=k[mid].a&&rp>k[mid-1].a){
			return k[mid].b;
		}else if(rp>k[mid].a)l=mid;
		else if(rp<=k[mid-1].a)r=mid;
	}
//	cout<<l<<" "<<r;
	if(rp<=k[l].a)return k[l].b;
	else if(rp>k[l].a)return k[r].b;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i].a>>k[i].b;
		k[i].a+=k[i-1].a;
	}
	for(int i=1;i<=k[n].a/2;i++){
		if(hs(i)!=hs(k[n].a-i+1)){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
