#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,ans;
long long r[200010];
long long l[200010];
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %d %c",&a[i],&c[i]);
		l[i]=cnt+1;
		cnt+=a[i];
		r[i]=cnt;
	}
	cnt=0;
	int i=1,j=n;
	while(i<j){
		if(r[i]<r[n]-l[j]+1){
			if(c[i]!=c[j])ans=r[i];
			i++;
		}
		else if(r[i]>r[n]-l[j]+1){
			if(c[i]!=c[j])ans=r[n]-l[j]+1;
			j--;
		}
		else{
			if(c[i]!=c[j])ans=r[i];
			i++;
			j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
