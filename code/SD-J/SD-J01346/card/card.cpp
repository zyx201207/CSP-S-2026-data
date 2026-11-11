#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		int cnt=0,sum=0; 
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			bool flag=0;
			int q;
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]) flag=1,q=k;
			} 
			if(flag==0) b[++cnt]=a[j];
			if(flag){
				for(int x=q+1;x<=cnt;x++){
					cnt--;
					b[x]=0;
				}
			}
			for(int x=1;x<=cnt;x++){
				t[b[x]]++;
			}
		}
		for(int x=1;x<=n;x++){
			cout<<t[a[x]]<<" ";
		}
	}
	return 0;
}

