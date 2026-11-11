#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,a[500005],s[300005],c[500005];
int num[300005],pos[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)	num[i]=pos[i]=0;
		for(int j=1;j<=n;j++)	c[i]=0;
		for(int j=i;j<=n;j++) {
			
			if(num[a[j]]!=0)	{
				for(int k=pos[a[j]];k<=n;k++) {
					num[c[k]]--;
					c[k]=0;
				}
			}
			
			c[j] = a[j];
			num[a[j]]++;
			pos[a[j]] = j;
		}
		for(int j=1;j<=n;j++) s[j] += num[j];
	}
	for(int i=1;i<=m;i++) cout << s[i] << " ";
	return 0;
}
