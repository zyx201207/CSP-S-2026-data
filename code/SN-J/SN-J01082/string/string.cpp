#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
long long ans=0;
long long len=0;
int main(){
	freopen("string.in" ,"r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long l=a[0],r=a[n-1];
	long long lc=0,rc=n-1;
	long long ans=0;
	while(1){
		if(l>r){
			if(c[lc]!=c[rc]){
				ans+=r;
				l-=r;
				rc--;
				if(lc==rc) break;
				r=a[rc];
			}
			else{
				l-=r;
				rc--;
				if(lc==rc) break;
				r=a[rc];
			}
		}
		else{
			if(c[lc]!=c[rc]){
				ans+=l;
				r-=l;
				lc++;
				if(lc==rc) break;
				l=a[lc];
			}
			else{
				r-=l;
				lc++;
				if(lc==rc) break;
				l=a[lc];
			}
		}
	}	
	cout<<ans;
	
	return 0;
}
