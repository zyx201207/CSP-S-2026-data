#include<bits/stdc++.h>
using namespace std;
int n,m,s=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n],b[m+1],c[m+1],t[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		c[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			b[j]=0;
			t[j]=0;
		}
		for(int j=i;j<n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
				c[a[j]]++;
				t[a[j]]=j;
			}
			else if(b[a[j]]==1){
				for(int k=t[a[j]];k<j;k++){
					c[a[k]]--;
					b[a[k]]=0;
				}
				t[a[j]]=j;
				c[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
