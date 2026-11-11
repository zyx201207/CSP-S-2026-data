#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	int n,m,i,j,c,ans=0;
	cin >> n >> m;
	int a[n][20]={0};
	if(m==1){
		for(i=0;i<n;i++){
			cin >> c;
			ans=(c>ans? c: ans);
		}
		cout << ans;
		return 0;
	}
	if(m==n){
		ans=INT_MAX;
		for(i=0;i<n;i++){
			cin >> c;
			ans &= c;
		}
		cout << ans;
		return 0;
	}
	for(i=0;i<n;i++){
		cin >> c;
		for(j=19;j>=0;j--){
			a[i][j]=c&1;
			c >>= 1;
			if(!c)break;
		}		
	}
	for(j=0;j<20;j++){
		c=0;
		for(i=0;i<n;i++){
			if(~a[i][j] && a[i][j])c++;
		}
		if(c<m)continue;
		if(c>=m){
			ans+=pow(2,20-j-1);
			for(i=0;i<n;i++){
			    if(!a[i][j]){
			    	for(int k=0;k<20;k++){
			    		a[i][k]=-1;
					}
				}
		    }
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
