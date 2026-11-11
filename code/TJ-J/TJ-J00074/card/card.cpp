#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,a[300005],vis[300005]; 
struct num{
	long long ans=0,cnt=0,pos1;
}b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	int pos=1;
	for(int i=1;i<=n;i++){
		pos=1;
		for(int j=i;j<=n;j++){
			b[a[j]].ans+=1;
			b[a[j]].cnt+=1;
			if(b[a[j]].cnt>1){
				for(int g=b[a[j]].pos1;g<pos;g++){
				    b[vis[g]].ans-=1;
					b[vis[g]].cnt-=1;
				}
			/*	for(int g=1;g<=m;g++){
					if((b[g].pos1<pos)&&(b[g].pos1>b[a[j]].pos1)){
						b[g].cnt-=1;
						b[g].ans-=1;
					}
				}*/
				pos=b[a[j]].pos1;
			}
			b[a[j]].pos1=pos;
			vis[pos]=a[j];
			pos+=1;
			
		}
		for(int j=1;j<=m;j++){
			b[j].cnt=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld",b[i].ans);
		cout<<" ";
	}
	return 0;
}
