#include<bits/stdc++.h>
using namespace std;
int n,m;
long long t=1,mx;
long long s[40],k[200010];
long long a[200010][40];
bool cmp(int x,int y){
	return x>y;
}
void in(int x,int sit){
	for(int i=1;i<=32;i++){
		if(x==0){
			return;
		}
		if(x%2==0){
			a[sit][i]=0;
			x/=2;
		}
		else{
			a[sit][i]=1;
			x=(x-1)/2;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%ld",&k[i]);
	}
	sort(k+1,k+n+1,cmp);
	for(int i=1;i<=n;i++){
		in(k[i],i);
	}
	for(int i=1;i<=n;i++){
		s[i]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=32;j++){
			if(a[i][j]==1&&s[j]==1){
				s[j]=1;
			}
			else{
				s[j]=0;
			}
		}
	}
	for(int i=1;i<=32;i++){
		if(s[i]==1){
			mx+=t;
		}
		t*=2;
	}
	printf("%ld",mx);
	return 0;
}
