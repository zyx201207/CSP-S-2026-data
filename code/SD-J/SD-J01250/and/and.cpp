#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,a[N],b[N][N],ans,mx,op,ans_a,ans_b,jj[N],ans_c;
int ji=1,ij;
void ada(int num){
	ji=1;
	while(num>0){
		b[ij][ji]=num%2;
		num/=2;
		ji++;
	}
	mx=max(mx,ji);
	return;
}
void bdb(){
	for(int i=mx;i>=1;i--){
		ans_a+=b[n][i]*pow(2,op);
		op++;
	}
	return;
}
void cdc(){
	for(int i=mx;i>=1;i--){
		ans_c+=jj[i]*pow(2,op);
		op++;
	}
	return;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ij++;
			ada(a[i]);
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=mx;j++){
				if(b[i][j]==1&&b[i-1][j]==1){
					b[i][j]=1;
				}
				else{
					b[i][j]=0;
				}
			}
		}
		bdb();
		cout<<ans_a;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ij++;
			ada(a[i]);
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=mx;k++){
					if(b[i][k]==1&&b[j][k]==1){
						jj[k]=1;
					}
				}
			}
		}
		cdc();
		cout<<ans_c;
	}
	return 0;
}
/*
3 3
9 19 29
1001
10011
11101
*/
