#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<char>c(n+1);
    long long all=0;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		all+=a[i];
    }
    long long ans=0;
    long long mid=all/2;
    int l=1,r=n;
    for(long long i=0;i<=mid&&l<r;i++){
		long long add=min(a[l],a[r]);
		i+=add;
		if(c[l]!=c[r])ans+=add;
		cout<<ans;
		ans-=max(0LL,i-(all-mid));
		if(a[l]>a[r])r--;
		else if(a[l]==a[r]){l++;r--;}
		else l++;
    }
    cout<<ans;
}
