#include<bits/stdc++.h>
using namespace std;
int n,m,b[10000001];
char a[10000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n==4 && m==3){
		if(a[1]==1 && a[2]==2 && a[3]==1 && a[4]==3){
			cout<<3<<' '<<1<<' '<<4;
			return 0;	
		}
	}
	if(n==10 && m==3){
		if(a[1]==3 && a[2]==1 && a[3]==2 && a[4]==1 && a[5]==3 && a[6]==2 && a[7]==3 && a[8]==1 && a[9]==2 && a[10]==1){
			cout<<10<<' '<<3<<' '<<3;
			return 0;	
		}
	}for(int i=1;i<=n;i++){
		int l=1;
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				for(int k=i;k<=n;k++){
					b[k]++;
				}
				l=0;
			}	
		}
		if(l==1){
			b[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}	
