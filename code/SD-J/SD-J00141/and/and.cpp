#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],sum,maxsum,maxk,ans[32],suml[200002],k,q[200002][32],b[32],o=1;
bool cmp(int x,int y){
	return x>y;
}
void l(int x){
	k=1;
	memset(ans,0,sizeof ans);
	while(x){
		int c=x%2;
		x/=2;
		ans[k]=c;
		k++;
	}
	maxk=max(maxk,k);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		l(a[i]);
	}
	for(int i=1;i<=n;++i){
		l(a[i]);
		for(int j=maxk;j>=1;--j){
			if(ans[j]==1){
				q[i][j]++;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=maxk;j>=1;--j){
			if(q[i][j]==1){
				b[j]++;
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=maxk;j>=1;--j){
//			cout<<q[i][j];
//		} 
//		cout<<endl;
//	}
//	for(int j=maxk;j>=1;--j){
//		cout<<b[j]<<' ';
//	}
	for(int j=maxk;j>=1;--j){
		if(b[j]>=m){
			sum=0;
			for(int i=1;i<=n;++i){
				if(q[i][j]==1){
					if(o==1)sum=a[i];
					else sum&=a[i];
					o++;
				}
			}
			maxsum=max(maxsum,sum);
		}
	}
	cout<<maxsum;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
