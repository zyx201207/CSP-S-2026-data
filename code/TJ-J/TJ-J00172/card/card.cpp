#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],ans[N];
struct stu{
	int flag,p;
}b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]].flag==0){
				b[a[j]].flag=1;
				b[a[j]].p=j;
			}
			else {
				for(int k=b[a[j]].p;k<=j;k++)b[a[k]].flag=0;
				b[a[j]].flag=1;
				b[a[j]].p=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j].flag==1){
				ans[j]++;
//				if(j==1)cout<<i<<endl;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
