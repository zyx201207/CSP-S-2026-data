#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],t[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool f=0,cnt=0;
			for(int l=1;l<=c;l++){
				if(b[l]==a[j]){
					cnt=l;
					f=1;
				}
			}
			if(f==1){
				for(int l=cnt+1;l<=c;l++){
					b[i]=0;
				}
				c-=cnt-1;
			}else{
				b[c]=a[j];
				c++;
			}
		}
		for(int j=1;j<=c;j++){
			t[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
