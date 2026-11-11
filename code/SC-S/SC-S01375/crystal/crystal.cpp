#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,c;
int a[N],r[N];//a数组为原数组，r数组为差分数组
bool flag[N];
void zhao(){
	int minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++) minn=min(minn,r[i]);
	int t=0;
	for(int i=1;i<=n;i++){
		if(r[i]==minn){
			if((a[i-1]-a[i])>m) continue;
			else{
				m=m-(a[i-1]-a[i]);
				a[i]=a[i-1];
				if(flag[i-1]!=1 && flag[i]!=1){
					flag[i-1]=1;
					flag[i]=1;
					c+=2;
				}
				else if(flag[i-1]==1 && flag[i]==0){
					flag[i-1]=1;
					flag[i]=1;
					c+=1;
				}
				else if(flag[i-1]==0 && flag[i]==1){
					flag[i-1]=1;
					flag[i]=1;
					c+=1;
				}
				zhao();
			}
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	for(int i=1;i<=n;i++) printf("%d",a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	r[1]=a[1];
	if(n!=1){
		for(int i=2;i<=n;i++){
			r[i]=a[i-1]-a[i];
			if(r[i]==0 && flag[i-1]!=1){
				c+=2;
				flag[i-1]=1;
				flag[i]=1;
			}
			else if(r[i]==0 && flag[i-1]==1){
				c++;
				flag[i]=1;
			}
		}
	}
	zhao();
	printf("%d",c);
	return 0; 
}
