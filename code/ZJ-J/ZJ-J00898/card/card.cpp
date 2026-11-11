#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=500005;
int n,m,a[maxn],b[maxn],c[maxn],len,anf,flag;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	int d[m+5];
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){
		len=0;anf=0;
		memset(d,0,sizeof(d));
		for(int j=i;j<=n;j++){b[++len]=a[j];d[a[j]]++;}
		for(int j=i;j<=n;j++){flag=1;
			if(d[a[j]]!=0){flag=0;}
			if(flag==1){
				len++;b[len]=a[j];
			}else{
				for(int k=1;k<=len;k++){
					if(b[k]==a[j]){anf=k;break;}
				}for(int k=anf+1;k<=n;k++){d[a[k]]=0;}
				len=anf;
			}
		}memset(d,0,sizeof(d));
		for(int j=1;j<=len;j++){
			if(d[b[j]]==0){c[b[j]]++;}
			d[b[j]]++;
		}
	}for(int i=1;i<=m;i++){cout<<c[i]<<" ";}
	return 0;
}
