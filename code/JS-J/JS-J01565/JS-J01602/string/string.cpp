#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5;
int n,len,ans,lastLeft=1e18;
int l[N+10],r[N+10];
char let[N+10];
int p;
signed main(){
	freopen("string.in" ,"r",stdin );
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		let[i]=c;
		l[i]=r[i-1]+1;
		r[i]=l[i]+a-1;
		len+=a;
	}
	p=n;
	lastLeft=len;
	for(int i=1;i<=n;i++){
		while(l[p]>=len-r[i]+1){
			
			if(let[p]!=let[i]){
				
				ans+=min(r[p],lastLeft)-l[p]+1;
			}
			lastLeft=l[p]-1;
			p--;
		}
		if(let[p]!=let[i]){
			
			ans+=lastLeft-len+r[i];
		}
		lastLeft=len-r[i];
		
	}
	cout<<ans/2<<endl;
	return 0;
}
