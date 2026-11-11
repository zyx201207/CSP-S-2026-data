#include <bits/stdc++.h>
using namespace std;
//zcy
#define int long long
const int N=2000010;
int c,t,n,d;
int zcy;
int x[N],q[N],h[N];//"q"dao wang qian neng fei dao zui yuan dao,"h"wang hou
signed main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>c>>t;
for(int o=1;o<=t;o++){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		}
	for(int i=1;i<=n;i++){
		int k=i+1,j=n,mid;
		while(k<=j){
			mid=(k+j)/2;
			if(x[mid]-x[i]<=d){
				h[i]=mid;
				k=mid+1;
				}
			else 
				j=mid-1;
			}
		k=1,j=i-1;
		while(k<=j){
			mid=(k+j)/2;
			if(x[i]-x[mid]<=d){
				q[i]=mid;
				j=mid-1;
				}
			else 
				k=mid+1;
			}
		}
	/*for(int i=1;i<=n;i++)
		cout<<h[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<q[i]<<" ";
	cout<<endl;*/
	for(int i=1;i<=n-3;i++){
		if(h[i]==n) break;
		if(h[i]==h[i+1]) continue; 
		int k=max(h[i]+1,i+3),j=n,mid;
		//if(h[i]==0||h[h[i]]==0) continue;
		while(k<=j){
			mid=(k+j)/2;
			if(q[mid]==0){
				j=mid-1;
				continue;
				}
			if(h[i]-q[mid]>1){
				k=mid+1;
				}
			if(h[i]-q[mid]<1){
				j=mid-1;
				}
			if(h[i]-q[mid]==1){
				int cnt=mid;
				while(h[i]-q[cnt]==1){
					//cout<<i<<" "<<cnt<<"\n";
				zcy++;
				cnt++;
				}
				int he=i,ta=cnt-1;
				int sum1=0,sum2=0;
				while(q[he]!=0&&(q[he+1]!=q[he])){
					sum1++;
					he=q[he];
					}
				while(h[ta]!=0&&(h[ta-1]!=h[ta])){
					sum2++;
					ta=h[ta];
					}
				zcy+=(sum1+1)*(sum2+1)-1;
				//cout<<(sum1+1)*(sum2+1)<<'\n';
				cnt=mid-1;
				while(cnt>=i+3&&h[i]-q[cnt]==1){
				zcy++;
				//cout<<i<<" "<<cnt<<"\n";
				//cout<<1103;
				cnt--;
				}
			break;
			}
			}
		}
	cout<<zcy<<'\n';
	memset(q,0,sizeof(q));
	memset(h,0,sizeof(h));	
	zcy=0;
	}
return 0;
}
