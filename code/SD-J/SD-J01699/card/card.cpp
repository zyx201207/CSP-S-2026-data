#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int n,m;
int maxn;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1;
	
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		int g=1;
		for(int j=i+1;j<=n;j++){
		
		for(int h=1;h<=g;h++){
			if(b[h]==a[j]){
				for(int k=h;k<=g;k++)
				b[k]=0;
				g=g-h;
				break;
			}
			
		}
		x[g]=a[i];
		}
		c[i]=
	}
	
	return 0;
} 

