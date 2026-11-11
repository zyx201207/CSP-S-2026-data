#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,ans;
struct Node{
	int len[N];
	char c[N];
}a,b;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string6.in","r",stdin);
//	freopen("string6.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a.len[i]>>a.c[i];
		b.len[n-i+1]=a.len[i];
		b.c[n-i+1]=a.c[i];
	}
	int i1=1,i2=1,j1=a.len[1],j2=b.len[1];
	while(i1<=n&&i2<=n){
		if(j1<j2){
			ans+=j1*(a.c[i1]!=b.c[i2]);
			j2-=j1;
			j1=a.len[++i1];
		}else if(j1>j2){
			ans+=j2*(a.c[i1]!=b.c[i2]);
			j1-=j2;
			j2=b.len[++i2];
		}else{
			ans+=j1*(a.c[i1]!=b.c[i2]);
			j1=a.len[++i1];
			j2=b.len[++i2];
		}
	}
	cout<<ans/2;
    return 0;
}
