#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,s[N],b[N],cnt,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			int k1=0; bool f1=0;
			for(int j=1;j<=cnt;j++){
				if(b[j]==a[k]){
					k1=j;
					f1=1;
				}
			}
			if(f1==0) b[++cnt]=a[k];
			else{
				for(int i=k1;i<=cnt;i++) b[i]=0;
				cnt=k1; b[cnt]=a[k];
			}
		}
		for(int j=1;j<=cnt;j++)
			s[b[j]]++;
		memset(b,0,sizeof(b));
		cnt=1;
	}
	for(int i=1;i<=m;i++)
		cout<<s[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/