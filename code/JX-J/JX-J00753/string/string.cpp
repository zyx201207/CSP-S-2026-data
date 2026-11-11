#include<bits/stdc++.h>
using namespace std;
long n,sum,k=1,ans;
long a[200005];
char c[200005],b[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            b[k]=c[i];
            k++;
	}
	}
	for(int i=1;i<=n/2;i++){
        if(b[i]!=b[sum-i])ans++;
	}
	cout<<ans;
	return 0;
}
