#include<bits/stdc++.h>
using namespace std;
struct Node{
	int n;
	string str;
}a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	long long T,ans=0,cnt=0,j=1;
//	cin>>T;
//	while(T--){
//		cin>>a[j].n>>a[j].str;
//		cnt+=a[j].n;
//		j++;
//	}
//	long long k1=1,k2=cnt,j1=1,j2=j;
//	while(k1<=k2){
//		if(k1>a[j1].n){
//			j1++;
//		}
//		if(k2<a[j2].n){
//			j2--;
//		}
//		if(a[j1].str!=a[j2].str) ans++;
//		k1++;k2--;
//	}
//	cerr<<cnt<<" "<<j;
//	cout<<ans;
	int T,n,ans=0,cnt=0;
	string str,mb="";
	cin>>T;
	while(T--){
		cin>>n>>str;
		for(int i=0;i<n;++i){
			mb+=str;
		}
		cnt+=n;
	}

	for(int i=0;i<cnt/2;i++){
		if(mb[i]!=mb[n-i-1]) ans++;
	}
	cout<<ans;
	
	return 0;
}
