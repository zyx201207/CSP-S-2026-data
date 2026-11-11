#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],o=0,b[N],k[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i-o];
		b[i]=1;
		if(a[i-o-1]==a[i-o]){
			o++;
			b[i-o-1]++;
		}
	}for(int x=1;x<=n-o;x++){
		for(int i=x;i<=n-o;i++){
			if(k[a[i]]==0){
				k[a[i]]=i;
			}else if(k[a[i]]!=0){
				for(int j=k[a[i]];j<=i;j++){
					k[a[j]]=0;
				}
				k[a[i]]=i;
			}
		}for(int i=1;i<=m;i++){
			if(k[i]!=0)d[i]+=b[x];
			k[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
