#include<iostream> 
#include<vector> 
#include<cmath> 
#include<algorithm> 
#include<map> 
#include<set> 
#include<cstdio>
#include<string> 
#include<cstring>
using namespace std;
int ans[300005],a[500005],n,m;
struct boo{
	bool bo;
	int now;
}b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],ans[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++)
			b[a[i]].bo=false,b[a[i]].now=0;
		for(int j=i;j<=n;j++){
			if(!b[a[j]].bo) b[a[j]].bo=true,b[a[j]].now=j;
			else{
				for(int k=1;k<=m;k++){
					if(a[k]==a[j]) continue;
					if(b[k].now>b[a[j]].now){
						ans[k]--;
						b[a[j]].now=0;
						b[a[j]].bo=false;
					}
				}
				b[a[j]].now=j;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
