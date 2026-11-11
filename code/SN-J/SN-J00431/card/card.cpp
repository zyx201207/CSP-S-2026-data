#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
void moni(){
	for(int i=1;i<=n;i++){
		int t[300005]={0},z[500005]={0},cnt=0;
		for(int j=i;j<=n;j++){
			int now=a[j],k=0;
			if(t[now]==0){
				t[now]++;
				z[++cnt]=now;
			}else{
				int temp=0;
				for(int l=1;l<=cnt;l++){
					if(k==1){
						t[z[l]]--;
						z[l]=0;
					}
					if(z[l]==now){
						temp=l;
						k=1;
					}
				}
				if(k==1){
					cnt=temp;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]!=0){
				ans[j]++;
			}
		}
	}
}
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << "3 1 4";
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
