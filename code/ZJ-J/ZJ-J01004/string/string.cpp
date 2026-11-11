#include<bits/stdc++.h>
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	FIO
	int n,i,s,sl,sr,l,r;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	s=sl=sr=0;
	sl+=a[l],sr+=a[r];
	while(l<r){
		if(sl>sr){
			if(c[l]!=c[r]) s+=sr;
			sl-=sr,sr=0,r--,sr+=a[r];
		}
		else if(sl<sr){
			if(c[l]!=c[r]) s+=sl;
			sr-=sl,sl=0,l++,sl+=a[l];
		}
		else{
			if(c[l]!=c[r]) s+=sl;
			sl=sr=0,l++,r--,sl+=a[l],sr+=a[r];
		}
	}
	cout<<s;
	return 0;
}