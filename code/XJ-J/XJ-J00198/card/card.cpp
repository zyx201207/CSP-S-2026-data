#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],b[500005][500005],t[300005],c[300005],k,cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		for(int i=x;i<=n;i++){
		if(t[a[i]]==0){
			b[x][++k]=a[i];
			t[a[i]]=1;
			c[a[i]]=i;
		}
		else{
			for(int j=i;j>=c[a[i]];j++){
				b[x][k--]=0;
				t[a[j]]=0;
				c[a[j]]=0;
			}
		}
	}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==b[i][j]){
				cnt++;
			}
			else{
				break;
			}
		}
	}
	cout<<cnt<<" ";
	
	return 0;
}
