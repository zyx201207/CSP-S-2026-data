#include<bits/stdc++.h>//T3->and  时间O(120n)可行 
using namespace std;
const int N=200010;
long long n,m,a[N][35],mx,sum[35],n_sum[35];//n_sum->new_sum
bool flag[N],bg=0;//bg->begin
long long ret=0,al_fl=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long i,j,k;
	for(i=0;i<n;i++){
		long long x,id=0;
		cin>>x;
		while(x>0){
			a[i][id]=x%2;
			if(x%2==1)sum[id]++;
			id++;
			mx=max(mx,id);
			x/=2;
		}//O(30n)
	}for(i=mx;i>=0;i--){
		//可优化，空间换时间，之前先存这里不用循环(优化) 
		if(al_fl==m){
			while(i>=0){
				bool now=1;
				for(j=0;j<n;j++){
					if(flag[j]==1&&a[j][i]==0){
						now=0;break;
					}
				}if(now==1)ret+=(1<<i);
				i--;
			}break;//O(30n)
		}
		if(bg==0){
			if(sum[i]>=m){
				for(j=0;j<n;j++){
					if(a[j][i]==1){
						flag[j]=1;
						al_fl++;
						for(k=i-1;k>=0;k--){
							if(a[j][k]==1)n_sum[k]++;
						}
					}
				}bg=1;
				ret+=(1<<i);
				continue;
			}else continue;
		}else {
			if(n_sum[i]>=m){
				for(j=0;j<n;j++){
					if(flag[j]==0)continue;
					if(a[j][i]==0){//不选，剪掉 
						flag[j]=0;
						al_fl--;
						for(k=i-1;k>=0;k--){
							if(a[j][k]==1)n_sum[k]--;
						}
					}
				}ret+=(1<<i);
				continue;
			}else continue;//O(60n)
		}
	}cout<<ret;
	return 0;
}
