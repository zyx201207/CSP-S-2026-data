#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5,NN=3e5;
int a[N],b[NN],out[NN],p,f,l;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int i=1;i<=n;i++){//进行的局数 
		
		int chupai=i;//出牌的起始位置 
		p=1;//放置位置 
		for(int j=1;j<=n+1-i;j++){//当局操作 
			f=1;//标记是否重复 
			for(int k=1;k<p;k++){//检查数组是否重复 
				if(b[k]==a[chupai]){ 
					f=0;
					for(l=k;l<p;l++)
					b[l]=0;
					p-=(l-k);
					
					break;
				}
			}
			if(f==0){
				b[p]=a[chupai];
				chupai++;
				p++;
				continue;
			}
			else if(f==1){
				b[p]=a[chupai];
				p++;
				chupai++;
			}
		}
		/*cout<<p;
		for(int j=1;j<p;j++){
			cout<<b[j]<<" ";
		}
		cout<<endl;*/
		for(int j=1;j<=m;j++){
			for(int k=1;k<p;k++){
				if(b[k]==j) {
					out[j]++;
					break;
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<out[i]<<" ";
	}
	return 0;
}
