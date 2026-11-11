//西宫南内多秋草，叶落满阶红不扫。 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,temp;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		temp=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=temp;
		a[l]-=temp;
		a[r]-=temp;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
