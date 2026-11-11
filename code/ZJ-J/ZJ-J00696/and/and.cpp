#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],cnt[31];
int b[31][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int co=a[i];
		int g=0;
		while(co!=0){
			if(co%2==1){
				cnt[g]++;
				b[g][i]=1;
			} 
			co/=2;
			g++;
		}
	}
	for(int i=29;i>0;i--){
		if(cnt[i]>=m){
			int y=0,mx,ok=1;
			for(int j=1;j<=n;j++){
				if(b[i][j]==1){
					if(ok==1){
						mx=a[j];
						ok=0;	
					}else{
						mx&=a[j];
					} 
					y++;
				}
				if(y>=m){
					cout<<mx;
					return 0;
				}
			}
			cout<<y<<'\n';
		}
	}
	return 0;
} 