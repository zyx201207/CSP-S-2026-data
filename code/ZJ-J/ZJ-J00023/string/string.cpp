#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int a[maxn],n;
char c[maxn];
long long int ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]>a[j])a[i]-=a[j],j--;
			else a[j]-=a[i],i++;
		}
	}
	cout<<ans;
	return 0;
}