#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long x,ma,ans[50],sum=0
;
bool b[N];
struct node{
	bool bo[50];
}a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long cnt=1;
		cin>>x;
		while(x){
			a[i].bo[cnt]=x%2;ans[cnt]+=x%2;
			x/=2;
			cnt++;
			
		}
//		cout<<cnt<<endl;
		ma=max(ma,cnt);
	}
	while(ma>=1){
		if(ans[ma]>=m){
			for(int i=1;i<=n;i++){
				if(a[i].bo[ma]==0&&!b[i]){
					for(int j=1;j<=50;j++){
						ans[j]-=a[i].bo[j];
						b[i]=1;
					}
				}
			}
			long long sum1=1;
			for(int i=2;i<=ma;i++){
				sum1*=2;
			}
			sum+=sum1;
		}
		ma--;
		
	}
	cout<<sum;
	return 0;
}
