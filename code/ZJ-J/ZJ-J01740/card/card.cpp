#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[500005];
int b[500005];
int c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=n;
		for(int j=i;j<=n;j++){
			bool f=false;
			for(int k=n-j+i+1;k<=n;k++){
				if(b[k]==a[j]){
					f=true;
					break;
				}
			}
			if(f==true){
				for(int k=n-j+i+1;k<=n;k++){
					b[k]=0;
				}
				b[n]=a[j];
				t=n-1;
				continue;
			}
			t--;
			b[t]=a[j];
		}
		for(int i=1;i<=n;i++){
			c[b[i]]++;
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}