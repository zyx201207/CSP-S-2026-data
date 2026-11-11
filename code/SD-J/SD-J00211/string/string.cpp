#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
long long cnt,n,A,len,l,r;
char C;
long long a[N],pre[N],ans;
char c[N];
int al[N],cl[N],ar[N],cr[N];
int cntl,cntr,lenl,lenr;
long long search_max(long long num){
	int l=1,r=cnt,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(pre[mid]<=num){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
long long search_min(long long num){
	int l=1,r=cnt,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(pre[mid-1]+1>=num){
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A>>C;
		len+=A;
		if(C==c[cnt])
			a[cnt]+=A;
		else
			a[++cnt]=A,c[cnt]=C,pre[cnt]=pre[cnt-1]+a[cnt];
	}
	l=search_max(len/2);
	r=search_min(len/2+1+(len&1));
	for(int i=1;i<=l;i++)
		++cntl,al[cntl]=a[i]+al[cntl-1],cl[cntl]=c[i],lenl+=a[i];
	for(int i=cnt;i>=r;i--)
		++cntr,ar[cntr]=a[i]+ar[cntr-1],cr[cntr]=c[i],lenr+=a[i];
	cntl=cntr=1;
	if(max(lenl,lenr)==len){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=min(lenl,lenr);i++){
		if(i>al[cntl])cntl++;
		if(i>ar[cntr])cntr++;
		if(cl[cntl]!=cr[cntr])ans++;
	}
	for(int i=lenl+1;i<=lenr;i++){
		if(i>al[cntl])cntl++;
		if(cl[cntl]!=c[l+1])ans++;
	}
	for(int i=lenr+1;i<=lenl;i++){
		if(i>ar[cntr])cntr++;
		if(cr[cntr]!=c[l+1])ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

