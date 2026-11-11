#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	bool f=1;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]>3) f=0;
	}
	int cnt=0;
	if(m==1){
		sort(a+1,a+n+1);
		printf("%d",a[n]);
	}else if(m==n){
		cnt=a[1];
		for(int i=2;i<=n;i++) cnt&=a[i];
		printf("%d",cnt);
	}else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				cnt=max(cnt,a[i]&a[j]);
		printf("%d",cnt);
	}else if(f){
		int t[4]={0,0,0,0};
		for(int i=1;i<=n;i++) t[a[i]]++;
		if(t[3]>=m) cnt=3;
		else if(t[2]+t[3]>=m) cnt=2;
		else if(t[1]+t[3]>=m) cnt=1;
		else cnt=0;
		printf("%d",cnt);
	}
	else{
		int max1=0,max2=0;
		for(int i=1;i<=n;i++){
			if(max1>=a[i]) max2=max(max2,a[i]); 
			else max2=max1,max1=a[i];
		}
		printf("%d",max2);
	}
	return 0;
} 
