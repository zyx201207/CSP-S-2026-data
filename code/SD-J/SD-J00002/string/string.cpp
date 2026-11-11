#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,cnt,l,r,mi;//十年OI一场空，不开long long_____ 
string cr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n); 
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>cr[i];
		if(cr[i]==cr[i-1]){
			a[i-1]+=a[i];
			i-=1;
			n-=1;
		}
	}//米忽悠还我命来,蛤蟆广还我命来，117还我命来，DF还我命来 
	l=1;
	r=n;
	while(l<=r){
		if(cr[l]==cr[r]){
			mi=min(a[l],a[r]);
			if(a[l]==a[r]){
				l++,r--;
				continue;
			}
			if(a[l]==mi){
				a[r]-=mi;
				l++;
				continue;
			}
			if(a[r]==mi){
				a[l]-=mi;
				r--;
				continue;
			}
		}
		if(cr[l]!=cr[r]){
			mi=min(a[l],a[r]);
			if(a[l]==a[r]){
				cnt+=a[l],l++,r--;
				continue;
			}
			if(a[l]==mi){
				cnt+=mi;
				a[r]-=mi;
				l++;
				continue;
			}
			if(a[r]==mi){
				cnt+=mi;
				a[l]-=mi;
				r--;
				continue;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
} 
