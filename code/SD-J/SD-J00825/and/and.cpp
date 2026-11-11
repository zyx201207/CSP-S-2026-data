#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200009;
int a[N];
int n,m;
unsigned long long ans;
bool bit[N][31];
int bitsum[31];

void solve(int a,int t){
	int cnt=0,sum=1;
	while(a>=sum*2){
		cnt++;
		sum=sum*2;
	}
	bit[t][cnt]=1;
	if(a>sum){
		if(a-sum==1){
			bit[t][0]=1;
		}
		else{
			solve(a-sum,t);
		}
	}
	return;
}



signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		solve(a[i],i);
	}
	for(int i=0;i<=30;i++){
		for(int j=1;j<=n;j++){
			if(bit[j][i]){
				bitsum[i]++;
			}
		}
	}
	int t1=30;
	bool ts=0;
	while(t1>0){
		for(int i=t1;i>=0;i--){
			if(m<=bitsum[i]){
				if(m==bitsum[i]){
					ts=1;
				}
				t1=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(bit[i][t1]!=1){
				for(int j=0;j<=30;j++){
					bit[i][j]=0;
				}
			}
		}
		if(ts==1)
			break;
	}
	for(int i=0;i<=30;i++){
		for(int j=1;i<=n;j++){
			bitsum[i]+=bit[j][i];
		}
	}
	for(int i=0;i<=30;i++){
		if(bitsum[i]<m){
			bitsum[i]=0;
		}
	}
	int sum=1;
	for(int i=0;i<=30;i++){
		if(bitsum[i]!=0){
			if(i=0){
				ans+=1;
			}
			else{
				for(int j=1;j<=i;j++){
					sum=sum*2;
				}
				ans+=sum;
				sum=1;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
