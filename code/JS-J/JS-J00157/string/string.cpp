#include<bits/stdc++.h>
using namespace std;
const int N=2e8+1e7+4e6;
long long a[N];
char b[N];
char c[N];
long long n,sum=0;
long long ans=0,x=1,l,r;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			c[x]=b[i];
			x+=1;
		}
		sum+=a[i];
	}
	if(sum%2==1){
		l=sum/2;
		r=l+2;
		while(l>=1&&r<=sum){
			if(c[l]!=c[r])ans++;
			l-=1;
			r+=1;
		}
	}
	else{
		l=sum/2;
		r=l+1;
		while(l>=1&&r<=sum){
			if(c[l]!=c[r])ans++;
			l-=1;
			r+=1;
		}
	}
	cout<<ans;
return 0;
}
