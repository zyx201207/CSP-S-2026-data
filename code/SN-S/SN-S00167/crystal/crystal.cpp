#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X "crystal"
#define FIN freopen(X".in","r",stdin)
#define FOUT freopen(X".out","w",stdout)
int n,m,s,c,a[500005],u=1,b=1;
signed main(){
	FIN;
	FOUT;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2&&i!=1){
			c=a[i]-a[i-1];	
		}else{
			if(a[i]-a[i-1]!=c){
				b=0;
			}
		}
		if(a[i]!=i){
			u=0;
		}
	}
	if(u==1){
		int i=0;
		while(s<=m){
			i++;
			s=s+i;
			//cout<<i<<s<<" ";
		}
		cout<<i-1;
	}else{
		if(b==0){
			s=m/c;
		}
		cout<<s;
	}
	return 0;
}
