#include<iostream> 
#include<string>
#include<cstring>
using namespace std;
long long n,a[500005],cnt[500005],m,f[500005],f1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=j;
			}else{
				for(int k=f[a[j]];k<j;k++){
					if(f[a[k]]==k){
						f[a[k]]=0;
					}
				}
				f[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]!=0){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
