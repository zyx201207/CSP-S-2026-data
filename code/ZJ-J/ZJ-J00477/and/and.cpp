#include<bits/stdc++.h>
using namespace std;
int a[200005];
int f[200005];
int n,m;
long long maxx=-1e6;
int l[200005];
int lcx[55];
int sjx[55];
int c[55];
int ze(int x){
	memset(lcx,0,sizeof(lcx));
	int i=0;
	while(x!=0){
		i++;
		lcx[i]=x%2;
		x=x/2;
	}
	return i;
}
int zlc(int x){
	memset(sjx,0,sizeof(sjx));
	int i=0;
	while(x!=0){
		i++;
		sjx[i]=x%2;
		x=x/2;
	}
	return i;
}
void dfs(int step,long long sum){
	if(step==m){
		if(sum>maxx) maxx=sum;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			if(step==0){
				step=step+1;
				l[step]==a[i];
				f[i]=1;
				dfs(step,l[step]);
				step=step-1;
				l[step]=0;
				f[i]=0;
			}else{
				step++;
				l[step]==a[i];
				memset(c,0,sizeof(c));
				int len=ze(sum)+zlc(l[step])-max(ze(sum),zlc(l[step]));
				for(int j=1;j<=len;j++){
					if(lcx[j]==1&&sjx[j]==1){
						c[j]=1;
					}else{
						c[j]=0;
					}
				}
				int linshi=sum;
				sum=0;
				for(int j=1;j<=len;j++){
					if(c[j]==1){
						sum=sum+pow(2,j-1);
					}
				}
				f[i]=1;
				dfs(step,sum);
				f[i]=0;
				step--;
				sum=linshi;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
		}
	}
	//dfs(0,0);
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
