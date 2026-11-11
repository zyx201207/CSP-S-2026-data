#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[200005];char c[200005];
	for(int i = 1;i<=n;++i)
		cin>>a[i]>>c[i];
	long long ans=0,j=n,i=1;
	while(i<=j&&a[i]!=0&&a[j]!=0){
		if(c[i]==c[j]){
			if(a[i]>a[j]){a[i]-=a[j];a[j]=0;j--;}
			else if(a[i]<a[j]){a[j]-=a[i];a[i]=0;i++;}
			else {a[i]=a[j]=0;i++;j--;}
			}
		while(c[j]!=c[i]&&i<=j){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];a[j]=0;
				j--;
			}
			else if(a[j]>a[i]){
				ans+=a[i];
				a[j]-=a[i];a[i]=0;
				i++;
			}
			else if(a[i]==a[j]){
				ans+=a[i];a[i]=a[j]=0;
				i++;j--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

