#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N+5];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=20){
		int ans=0;
		for(int i=0;i<=pow(2,n)-1;i++){
			int ans1,k=0,t=i,l=n,flag=1;
			while(t!=0){
				k+=t%2;
				t/=2;
			}
			if(k!=m) continue;
			t=i;
			while(t!=0){
				if(t%2){
					if(flag){
						ans1=a[l]; 
						flag=0;
					}
					else ans1=ans1&a[l];
				}
				t/=2;
				l--;
			}
			ans=max(ans,ans1);
		}
		printf("%d\n",ans);
		return 0;
	}
	else if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx<<"\n";
		return 0;
	}	
	else if(m==n){
		int maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx<<"\n";
		return 0;
	}	
	else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
