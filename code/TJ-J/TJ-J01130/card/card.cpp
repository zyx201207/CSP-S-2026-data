#include<iostream>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	int n,m,a[500005],c[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int b=i;
			while(b<j){
				if(a[b]!=a[j]){
					c[j+(i*n)]=a[i];
				}
				b++;
			}
		}
	}
	int num[m+5];
	for(int l=1;l<=n;l++){
	    for(int i=l;i<=n;i++){
		    for(int j=1;j<=m;j++){
			    if(c[i]==j){
				    num[j]++;
			    }
		    }
	    }
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	freopen("card.out","w",stdout);
	return 0;
}
