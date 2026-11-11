 #include<bits/stdc++.h>
 using namespace std;
 long long a[200002];
 long long ans=pow(2,31)-1;
 int main(){
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	int n,m,ma=0;
 	scanf("%d%d",&n,&m);
 	for(int i=0;i<n;i++){
 		scanf("%lld",&a[i]);
 		if(a[i]>ma)ma=a[i];
	}
	if(m==n){
	    for(int i=0;i<n;i++){
	    	ans=ans&a[i];
		}
	}
	else if(m==1)ans=ma;
	else if(m==2){
		ans=0;
		for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(a[i]&a[j]>ans)ans=a[i]&a[j];
	}
	printf("%d",ans);
 	return 0;
 }
