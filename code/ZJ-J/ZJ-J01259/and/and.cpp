#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],tot,mm[32],c[200005],ans,tot1;
bool b[200005][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	mm[0]=1;
	for(int i = 1 ; i<= 31; i ++)mm[i]=2*mm[i-1];
	cin >> n >> m;
	tot=n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		c[i]=i;
		for(int j = 0 ; j <= 30 ; j++)b[i][j]=(a[i]&mm[j]);
	}
	for(int i = 1; i <= n ; i++)a[i]=c[i];
	int k=30,cnt=0;
	while(k>=0){
		tot1=0;
		for(int i = 1 ; i <= tot ; i++){
			cnt+=b[a[i]][k];
			if(b[a[i]][k])c[++tot1]=a[i];
		}
		if(cnt>=m){
			ans+=mm[k];
			for(int i = 1; i <= tot1 ; i++)a[i]=c[i];
			tot=tot1;
		}
		k--;
		cnt=0;
	}
	cout << ans;
	return 0 ;
}
