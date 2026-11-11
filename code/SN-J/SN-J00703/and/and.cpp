//yangzirui xianjiaotongdaxuefushuzhongxue SN-J00703
#include<bits/stdc++.h>
using namespace std;
int maxx=INT_MIN,m,n,a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}else{
		for(int i=1;i<=n;i++){
			int max1=a[i],maxx1=INT_MIN;
			for(int q=1;q<=n;q++){
				b[q]=a[q];
			}
			b[i]=0;
			for(int k=1;k<=m-1;k++){
				maxx1=INT_MIN;
				int maxa;
				for(int j=1;j<=n;j++){
					if((b[j]&max1)>maxx1){
						maxx1=b[j]&max1;
						maxa=j;
					}
				}
				b[maxa]=0;
				max1=maxx1;
			}
			maxx=max(maxx1,maxx);
		}
		cout<<maxx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
