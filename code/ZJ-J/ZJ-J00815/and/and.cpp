#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N][40],b[40],c[N],ans,r=1,o;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=0;x!=0;j++){
			if(x%2==0){
				a[i][j]=0;
			}else{
				a[i][j]=1;
				b[j]++;
				x--;
			}
			x/=2;
		}
	}for(int i=0;i<=32;i++)r*=2;
	for(int i=32;i>=0;i--){
		r/=2;
		if(b[i]>=m){
			if(o==0){
				for(int j=1;j<=n;j++){
					if(a[j][i]==1){
						c[j]=1;
					}
				}
				o=1;
				ans+=r;
			}else if(o==1){
				int sum=0;
				for(int j=1;j<=n;j++){
					if(a[j][i]==1&&c[j]==1){
						sum++;
					}
				}
				if(sum>=m){
					ans+=r;
					for(int j=1;j<=n;j++){
						if(a[j][i]==0){
							c[j]=0;
						}
					}
				}
			}			
		}
	}
	cout<<ans;
	return 0;
}
