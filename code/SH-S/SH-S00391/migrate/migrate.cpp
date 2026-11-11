#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt;
int a[10005];
int f[10005];

int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrat3e.out","w",stdout);
	memset(f,0,n+1);
	cin>>c>>t;
	while(t!=0){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int l=1;l<=n-1;l++){
			int b=1;
			for(int r=l+1;r<=n;r++){
				int sum=a[r]-a[l];
				if(sum>d and r==l+1) {b=l;break;}
				else if(sum>d) break;
				
				if(sum==d and r-l+1>=3 ){
					int i=l;
					while(i>=1){
						if(f[i]!=0){
							cnt=cnt+l-b+f[i];f[r]=cnt;break;
						}
						else{
							cnt=cnt+l-b;
						}
						i--;
					}
				}
			}
		}
		cout<<cnt<<endl;
		t--;
	}
	return 0;
}
