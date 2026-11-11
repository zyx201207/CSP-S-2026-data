#include<bits\stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll n,m,a[N],o[N],ans[N],cnt,x[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(o[a[j]]==0||o[a[j]]>=cnt){
				ans[++cnt]=a[j];
				o[a[j]]=cnt;
			}else{
				cnt=o[a[j]];
			}
		}
		for(int j=1;j<=cnt;j++){
			x[ans[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<x[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}