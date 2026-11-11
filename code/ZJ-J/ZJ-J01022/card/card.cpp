#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[6000100];
long long b[6000100];
long long c[6000100];
long long cnt[400000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int v=1;v<=m;v++){
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		long long i=v;//b数组循环到的位置 
		long long x=1;//下一个c中空的位置 
		long long ps=0;//c数组长度 
		while(1){
			if(i>n){
				break;
			}
			long long bj=0;//标记是否存在 
			
			for(long long j=1;j<=ps;j++){
				if(c[j]!=b[i]){
					continue;
				}else{
					bj=j;
					break;
				}
			}
			if(bj==0){
				c[x]=b[i];
				ps++;
				x++;
				i++;
			}else{
				x=bj;
				for(long long k=bj;k<=ps;k++){
					c[k]=0;
				}
				c[x]=b[i];
				ps=x;
				x++;
				i++;
			}
		}
		for(long long o=1;o<=ps;o++){
			cnt[c[o]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
