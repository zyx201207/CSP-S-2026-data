#include <bits/stdc++.h>
using namespace std;
#define  fin(x)  freopen(x,"r",stdin)
#define  fout(x)  freopen(x,"w",stdout)
const int N=5e5;
int a[N],sum[N];
vector<int> v;
map<int,bool> mp;
bool flag=true;
int n,m;
int main()
{
	fin("card.in");
	fout("card.out");
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		flag=(a[i]>=a[i-1]);
	}
	if (flag){
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (a[j]!=a[j+1]){
					if (sum[a[j]]==0){
						sum[a[j]]++;
					}
				}
			}
		}
		for (int i=1;i<=m;i++){
			printf("%d ",sum[i]);
		}
		return 0;
	}
}
