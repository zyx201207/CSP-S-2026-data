#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long n,sum;
long long ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}  
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum-i+1]) ans++;
	}cout<<ans;
//	int l=1,r=n;
//	long long ll=1,lr=a[1],rl=sum-a[n]+1,rr=sum;
//	bool zl,zr;
//	//sum-i+1
//	while(1){
//		if(l==r) break;
//		if(lr>sum/2) lr=sum/2;
//		if(rl<=sum/2) rl=sum/2+1+(sum%2);
//		zl=0,zr=0;
//		if(sum-lr+1>rl){
//			if(c[lr]!=c[rl]){
//				ans+=(lr-ll+1);
//			}l++,zl=1;
//			rl-=(lr-ll+1);
//		}else if(sum-lr+1<rl){
//			if(c[lr]!=c[rl]){
//				ans+=(rr-rl+1);
//			}
//			r--,zr=1;
//			lr+=(rr-rl+1);
//		}else{
//			if(c[lr]!=c[rl]) ans+=(lr-ll+1);
//			r--,l++;
//			zl=1,zr=1;
//		}
//		if(zl){
//			lr++;
//			ll=lr;
//			lr=ll+a[l]-1;
//		}if(zr){
//			rl--;
//			rr=rl;
//			rl=rr-a[r]-1;
//		}
//		
//	}
//	ans+=((sum/2)!=(sum/2+1+(sum%2)));
//	//aaaac
//	cout<<ans;
	return 0;
}
