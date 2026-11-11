#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,k,ans,maxw=0,tong[100],zmaxw;
bool flagg=true;
struct node{
	int b[100];
	long long x;
	bool flag=true;
}a[N];
void shua(){
	memset(tong,sizeof(tong),0);
	for(int i=1;i<=40;i++){
		tong[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(a[i].flag==0)continue;
		for(int j=1;j<=40;j++){
			tong[j]+=a[i].b[j];
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		long long h=a[i].x,cnt=0;
		while(h){
			a[i].b[++cnt]=h%2;
			h/=2;
			maxw=max(maxw,cnt);
			tong[cnt]+=a[i].b[cnt];
		}
	}
	for(int h=maxw;h>=1;h--){
		if(tong[h]>=k){
			for(int i=1;i<=n;i++){
				if(a[i].b[h]!=1){
					a[i].flag=false;
				}
			}shua();
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].flag==1){
			if(flagg){
				ans=a[i].x;
				flagg=0;
			}else{
				ans&=a[i].x;
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
