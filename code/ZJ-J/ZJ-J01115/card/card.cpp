#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],tong[500050],lt[500050],dt[500050],p[500050];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=false;
	}
	if(m==n){
		for(int i=1;i<=m;i++)cout<<n-i+1<<" ";
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n])tong[a[i]]++;
			else {
				tong[1]++;
				tong[2]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<tong[i];
	}
	else if(f){
		int tmp[300050];
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1])tmp[a[i]]++;
			else {
				tmp[a[i]]++;
				for(int j=a[i];j<=a[i+1];j++)tmp[j]=tmp[a[i]];
			}
		}
		for(int i=1;i<=n;i++)cout<<tmp[i]<<" ";
	}
	else {
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]){
				tong[a[i]]++;
				continue;
			}
			else {
				for(int j=1;j<=m;j++){
					lt[j]=0;dt[j]=0;
				}
				for(int j=1;j<=n;j++)
					p[j]=1;
				for(int j=i;j<=n;j++){
					if(lt[a[j]]!=0&&p[lt[a[j]]]==1)for(int k=lt[a[j]];k<j;k++){
						p[k]=0;
					}
					lt[a[j]]=j;
				}
				for(int j=i;j<=n;j++)if(p[j])dt[a[j]]++;
				for(int j=1;j<=m;j++)if(dt[j])tong[j]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<tong[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
