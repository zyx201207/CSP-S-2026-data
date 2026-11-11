#include<bits/stdc++.h>
using namespace std;
int a[503305],b[503305],CR200J[503305];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int cnt=0;
		for(int j=i;j<=n;j++){
			int cnt1=0,flag=0;
			for(int x=1;x<=cnt;x++){
				if(b[x]==a[j]) flag=1;
				if(flag==1) b[x]=0,cnt1++;
			}
			cnt-=cnt1;
			b[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			CR200J[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<CR200J[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
//<CR400BF-5033||ZE 503302||ZE 503303||ZE 503304||ZEC 503305||ZE 503306||ZE 503307||CR400BF-5033>
