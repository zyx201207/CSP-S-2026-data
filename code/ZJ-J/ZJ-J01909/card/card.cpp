#include<bits/stdc++.h>
using namespace std;
int x,n,m,a[500005],b[300005],c[500005],t,s[300005];
int main(){
	freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=1;j<=m;j++)
			b[j]=0;
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]>1){
				while(1){
					x=c[t];
					b[c[t]]--;
					c[t]=0;
					t--;
					if(x==a[j]) break;
				}
			}
			t++;
			c[t]=a[j];
		}
		for(int j=1;j<=t;j++)
			 s[c[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}