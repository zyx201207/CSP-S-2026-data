#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005]; 
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),cin>>c[i];
	}
	int i=1,j=n;
	while(i<j){
		while(a[i]>=a[j]){
			if(c[i]!=c[j]) ans+=a[j]; 
			a[i]-=a[j--];
		}
		if(a[i]!=0) {
			if(c[j]!=c[i]) ans+=a[i];
			a[j]-=a[i];
		}
		i++;
	}
	printf("%lld",ans);
	return 0;
} 
