#include<bits/stdc++.h>
using namespace std;
long long n,cs,minn=1,maxn=0,ans=0;
char b[200000000000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
    	cin>>cs;
    	maxn+=cs;
    	for(long long j=minn;j<=maxn;j++){
    		if(j==minn) cin>>b[j];
    		else b[j]=b[j-1];
		}
		minn=maxn+1;
	}
	long long x=maxn;
	for(long long i=1;i<=maxn/2;i++){
		if(b[i]!=b[x]){
			ans++;
		} 
		x--;
	}
    cout<<ans;
	return 0;
}
