#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],len,ans[5005],outcard[5005],outcardcnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	bool A=0;
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]<a[i]-1){
			A=1;
		}
	}
	if(!A){
		for(int i=0;i<n-1;i++){
			if(a[i]==a[i+1]){
				a[i]=-1;
				len++;
			}
		}
		for(int i=0;i<n;i++){
			cout<<"1"<<' ';
			
		}
	}
	for(int i=0;i<n;i++){
		memset(a,0,sizeof(a));
		outcardcnt=0;
		for(int j=i;j<n;j++){
			outcard[outcardcnt]=a[j];
			outcardcnt++;
			for(int k=0;k<n;k++){
				if(outcard[k]==a[j]){
					for(int l=k;l<j;l++){
						outcard[l]=0;
						outcardcnt--;
					}
				}
			}
		}
		for(int j=0;j<outcardcnt;j++){
			ans[outcard[j]]++;
		}
	}
	for(int i=0;i<6;i++){
		if(ans[i]!=0){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
