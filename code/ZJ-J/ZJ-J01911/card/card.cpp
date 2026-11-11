#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[200005],b[100005],d[100005],t,c[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]++;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			b[j]=d[j];
		for(int j=i;j<=n;j++){
			if(b[a[j]]>=2){
				t=j;
				while(a[t]!=a[j+1]){
					j++;
					b[a[j]]--;
				}b[a[t]]--;
			}else{
				c[a[j]]++;
			}
		}d[a[i]]--;
	}for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
