#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],n;
char c[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int i=1;
	while(1){
		if(i>n){
			cout<<ans;
			return 0;
		}
		int k=min(a[i],a[n]);
		if(c[i]!=c[n])ans+=k;
		a[i]-=k;
		a[n]-=k;
		if(a[n]==0)n--;
		if(a[i]==0)i++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
