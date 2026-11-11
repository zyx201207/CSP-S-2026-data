#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(1){
		int x=min(a[i],a[j]);
		if(c[i]!=c[j]){
			ans+=x;
		}
		a[i]-=x;
		a[j]-=x;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
		if(i>=j)break;
	}
	cout<<ans;
	return 0;
}
