#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],ans[300005];
long long sp[500005],zp[500005];
long long slen,zlen;
long long sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	slen=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sp[i]=a[i];
	}
	while(n--){
		sum++;
		for(int i=sum;i<=slen;i++){
			sp[i]=0;
		}
		for(int i=1;i<=zlen;i++){
			zp[i]=0;
		}
		slen=n;
		zlen=0;
		for(int i=sum;i<=n;i++){
			bool flag=0;
			zp[zlen+1]=sp[i];//zp[1]=sp[1]//zp[2]=sp[2]
			zlen++;//1z 1//2z 1 2// 3z 1 2 1
			slen--;//4s 0 2 1 3//3s 0 1 3//2s 0 3
			sp[i]=0;
			for(int j=i+1;j<=slen+1;j++){
				sp[j-1]=sp[j];
			}//3s 2 1 3//2s 1 3//1s 3
			for(int j=1;j<=zlen-1;j++){
				if(zp[i]==zp[j]){
					flag=1;
				}
				if(flag==1){
					zp[j]=0;
					zlen--;
					sp[slen+1]=zp[j];
					slen++;
				}
			}
			if(flag==1){
				zp[zlen]=0;
				zlen--;
				sp[slen+1]=zp[i];
				slen++;
			}	
		}
		for(int i=1;i<=zlen;i++){
			ans[zp[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
