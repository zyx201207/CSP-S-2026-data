#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],k[N],wz;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	  cin>>a[i];
	  s[a[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		s[a[i]]-=1;
		for(int j=n;j>i;j--){
		    wz=j;
			if(s[a[j]]>1)break;
		}
		for(int e=wz;e<=n;e++)k[a[e]]++;
	}
	for(int i=1;i<=m;i++)cout<<k[i]<<" ";
	return 0;
}
