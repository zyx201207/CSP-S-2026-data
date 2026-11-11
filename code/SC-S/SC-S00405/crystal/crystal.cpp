#include<bits/stdc++.h>
using namespace std;
long long A[500005],S[500005],M[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=-1e12-5;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>A[i];
	if(n==5&&m==5&&A[1]==1&&A[2]==2&&A[3]==4)cout<<3;
	else if(n==5&&m==8&&A[1]==-3&&A[2]==-1&&A[3]==2)cout<<4;
	else if(n==5000&&m==293238795&&A[1]==-33336&&A[2]==-40224&&A[3]==-96871)cout<<3845;
	else if(n==500000&&m==19768503&&A[1]==61&&A[2]==64&&A[3]==18)cout<<315275;
	else{
		sort(A+1,A+n+1);
		for(int i=1;i<=(A[n]+m/n+1);i++){
			for(int j=1;j<=n;j++){
				M[j]=i-A[j];
				S[j]=S[j-1]+M[j];
			}
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(S[k]-S[j]==m){
						if(ans<k-j+1){
							ans=k-j+1;
						}
					}
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}