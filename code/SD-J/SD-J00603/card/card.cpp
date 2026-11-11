#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int yunxing[N],t[M];
int a[N],b[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		memset(yunxing,0,sizeof(yunxing));
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]=1;
				cnt++;
				yunxing[cnt]=a[j];
			}
			else{
				int k=1;
				for(k=1;k<=cnt;k++){
					if(yunxing[k]==a[j]){
						break;
					}
				}
				for(int p=k;p<=cnt;p++){
					t[yunxing[p]]--;
				}
				cnt=k;
				yunxing[cnt]=a[j];
				t[a[j]]++;
			}
		}
		for(int j=1;j<=cnt;j++){
			b[yunxing[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
