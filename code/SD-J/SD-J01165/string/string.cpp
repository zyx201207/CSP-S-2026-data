#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long ans;
long long i,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%s",&a[i],&c[i]);
	}
	i=1;
	j=n;
	while(i<=j){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
			}else{
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
			}else{
				a[j]-=a[i];
				a[i]=0;
			}
		}
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
