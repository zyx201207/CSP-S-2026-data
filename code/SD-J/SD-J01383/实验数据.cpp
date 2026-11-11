#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200000;
int n,m;
int num[N];
bool bol1[N],bol2[N];int sum=0;
void two1(int num){
	int wm[N];int cnt=0;
	for(int i=1;num!=0;i++){
		wm[i]=num%2;
		num/=2;
		cnt=i;
	}sum=max(sum,cnt);
	for(int i=cnt,j=1;i>=1;j++,i--){
		bol1[j]=wm[j];
	}
}
void two2(int num){
	int wm[N];int cnt=0;
	for(int i=1;num!=0;i++){
		wm[i]=num%2;
		num/=2;
		cnt=i;
	}sum=max(sum,cnt);
	for(int i=cnt,j=1;i>=1;j++,i--){
		bol2[j]=wm[j];
	}
}
int ten(bool bol[]){
	int cnt=0;
	for(int i=1;i<=sum;i++){
		int k;
		k=bol[i];
		for(int j=0;j<i-1;j++){
			k*=2;
		}
		cnt+=k;
	}
	return cnt;
}
void awy(bool bol1[],bool bol2[]){
	bool bol[sum];
	for(int i=1;i<=sum;i++){
		if(bol1[i]==1&&bol2[i]==1) bol[i]=1;
		if(bol1[i]==0&&bol2[i]==0) bol[i]=0;
		else bol[i]=0;
	}
	ten(bol);
}
bool pop[n];int cnt=0;
void a(int num[]){
	
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(pop[j]!=1&&cnt<m){
				pop[j]=1;
				cnt++;
			}
			else if(pop[j]==1) continue;
			if(cnt==m){
				for(int i=1;i<=n;i++){
					if()
				}
				cnt--;
				pop[j]=0;
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<"{";
//		
//	}
	return 0;
} 
