#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<= n;i++){
		memset(b,0,sizeof(b));
		for(int j = i;j<= n;j++){
			if(lower_bound(b,b+n+1,a[j])-b!=n+1){
				b[j]=a[j];
				int num=lower_bound(b,b+n+1,a[j])-b;
				for(int l =num;l<j;l++){
					b[l]=0;
				}
			}
			else{
				b[j]=a[j];
			}
		}
		for(int k = 1;k<= n;k++){
			if(b[i]>0){
				ans[k]++;
			}
		}
	}
	for(int i = 1; i<= n;i++){
		cout<<ans[i];
	}
	return 0;
} 
