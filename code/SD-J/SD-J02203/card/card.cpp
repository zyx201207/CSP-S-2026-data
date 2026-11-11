#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5000050];
int b[5000050];
int cntb=0;
int cntx[5000050];
int cnt=1;
bool flag=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int k=n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	while(n--){
		memset(b,0,sizeof(0));
		cntb=0;
		flag=0;
		for(int i=cnt; i<=k; i++){
			for(int j=1; j<=cntb; j++){
				if(b[j]==a[i]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				b[++cntb]=a[i];
			}else{
				memset(b,0,sizeof(0));
				cntb=0;
				b[++cntb]=a[i];
			}
		}
		for(int i=1; i<=cntb; i++){
			cntx[b[i]]++;
		}
		cnt++;
	}
	for(int i=1; i<=m; i++){
		cout<<cntx[i]<<" ";
	}
	return 0;
} 
