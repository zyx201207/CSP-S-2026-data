#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	ll cnt=0;
	for (int i=1,j=n;i<j;i++)
		while (a[i] && i<j){
			int x=a[i]>a[j] ? i : j,y=a[i]>a[j] ? j : i;
			cnt+=c[i]==c[j] ? 0 : a[y],a[x]-=a[y],a[y]=0;
			if (!a[j]) j--;
		}
	printf("%lld",cnt);
}
