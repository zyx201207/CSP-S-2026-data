#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	int l=1;
	int r=n;
	while(l!=r){
		if(a[l]<=a[r]){
			if(c[l]!=c[r]) cnt+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else{
			if(c[l]!=c[r]) cnt+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	printf("%lld",cnt);
	return 0;
}
