#include<bits/stdc++.h>
using namespace std;
int n,m,ans1[300005],a[500005],b[300005],k[500005],mm[500005];
inline long long read(){
	int c;long long anss=0;c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		anss=anss*10+c-'0';c=getchar();
	}
	return anss;
}
int main(){
	freopen("card.in","r",stdin);//IMPORTANT
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();//disappear1[i]=n+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0)b[a[j]]=j;
			else {
				if(k[b[a[j]]]==0){
					for(int l=b[a[j]];l<j;l++)k[l]=-1;
				}
				b[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			mm[a[j]]=max(mm[a[j]],k[j]+1);k[j]=0;
		}
		for(int j=1;j<=m;j++){
			b[j]=0;ans1[j]+=mm[j];mm[j]=0;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans1[i]);
	return 0;
}