#include <bits/stdc++.h>
using namespace std;
int a[10000005],flag[10000005][2],cnt1[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int r;
		flag[a[i]][1]=1;
		flag[a[i]][0]=i;
		for(r=i+1;r<=n;r++){
			if(flag[a[r]][1]==1){
				for(int aa=flag[a[r]][0];aa<=r;aa++){
					flag[a[r]][1]=0;
				}
			}
		}	
			
			flag[a[r]][1]=1;
			flag[a[r]][0]=r;	
		}
		for(int ss=1;ss<=n;ss++){
			if(flag[ss][1]==1){
				cnt1[ss]++;
			}
		}
		memset(flag,0,sizeof(flag));
		cout<<endl;
	
	for(int i=1;i<=m;i++){
		cout<<cnt1[i]<<" ";
	}
	return 0;
}
