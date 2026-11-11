#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int m,n,a[N],ans,ma,cnt[N];
int o[N];
inline void check(){
	int now=a[o[1]];
	for(int i=2;i<=m;i++){
	now&=a[o[i]];
}
	ans=max(ans,now);
}
void z(int step,int p){
	if(step==m+1){check();return;}
    for(int i=p+1;i<=n;i++){
    	o[step]=i;
    	z(step+1,i);
	}	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	bool b=0;
	bool B=0;
	for(int i=1;i<=30;i++)
	if(n==(1<<i))B=1;
	for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	ma=max(a[i],ma);
	for(int j=1;j<=30;j++)
	if(a[i]!=(1<<j)-1){
		b=1;
		break;
	}
	if(a[i]!=i-1)
	B=0;
	}
	if(b==0){
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1;i>n-m;i--)
		ans&=a[i];
		printf("%d",ans);
	}
	else if(B==1){
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1;i>n-m;i--)
		ans&=a[i];
		printf("%d",ans); 
	}
	else if(m==1){
		sort(a+1,a+1+n);
		printf("%d",a[n]);
	}
	else if(m==2){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(i!=j)
		ans=max(a[i]&a[j],ans);
		printf("%d",ans);
	}
	else if(m==n){
		for(int i=1;i<=n;i++)
		ans&=a[i];
		printf("%d",ans);
	}
	else if(ma<=4){
		for(int i=1;i<=n;i++)
		cnt[a[i]]++;
		if(cnt[ma]>=m)ans=ma;
		else {
			if(cnt[2]+cnt[3]>=m)ans=2;
			else if(cnt[1]+cnt[3]>=m)ans=1;
			else ans=0;
			printf("%d",ans);
		}
	}
	else {
		z(1,0);
		printf("%d",ans);
	}
	return 0;
}
