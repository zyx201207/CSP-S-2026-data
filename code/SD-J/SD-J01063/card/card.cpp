#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 5e5+10,MMAXNN = 3e5+10;
LL n,k,a[MAXN],b[MMAXNN],b_fin[MMAXNN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL sta = 1;sta<=n;sta++ ){
		
		memset(b,0,sizeof(b));//重置 
	
		for(LL i=sta;i<=n;i++){
			
			b[a[i]]++;//赋值 
			
			if(b[a[i]]==2){
				bool bb = 1;
				LL j = i-1;
				while(bb){
					if(a[j]==a[i]){
						bb = 0;
					}
					if(a[j]>0)b[a[j]]--,a[j] = -a[j];
					j--;
				}
			}//检查是否有两个 

		}
		
		for(LL j=1;j<=k;j++){
			b_fin[j]+=b[j];
		}
		for(LL i=1;i<=n;i++){
			a[i] = abs(a[i]);
		}
	}
	for(LL i=1;i<=k;i++){
		cout<<b_fin[i]<<' ';
	}
	return 0;
}

