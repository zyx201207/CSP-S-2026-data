#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m;
int a[N],mx;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int maxx=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if(m==1)cout<<maxx;
	else if(m==n){
		int cnt=a[1];
		for(int i=1;i<=n;i++){
			cnt&=a[i];
		}
		cout<<cnt<<endl;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx<<endl;
	}
	
	return 0;
}
