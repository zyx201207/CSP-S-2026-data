#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],mark[300005],bj=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mark[a[j]]==0){
				mark[a[j]]=1;
				b[a[j]]++;
				//cout<<a[j]<<"¼ÓÈë"<<endl;
			}
			else{
				b[a[j]]++;
				for(int k=i;k<j;k++){
					if(a[k]==a[j]||bj==1){
						bj=1;
						b[k]--;
						//cout<<a[k]<<"È¥³ý"<<endl;
					}
				}
				bj=0;
			}
		}
		for(int j=1;j<=n;j++){
			mark[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
