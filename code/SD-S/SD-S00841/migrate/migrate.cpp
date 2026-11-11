#include<bits/stdc++.h>
using namespace std;
long long C,T,n,d,x[100005];
long long sjm[1005][1005],sum=0;
void find(long long y){//从y开始跳计算 
//	cout<<"y="<<y<<endl;
	long long i=y,j=y;
	long long ss=1;
	while(i<n){
//		cout<<"i="<<i<<"ss="<<ss<<endl;
		if(x[i+1]-x[j]<=d&&i<=n){
			while(x[i+1]-x[j]<=d&&i<=n){
//				cout<<j<<" "<<i<<" "<<ss<<" ";
//				cout<<"x[i+1]="<<x[i+1]<<"x[j]="<<x[j]<<endl;
				
				i++;
				if(i>=100){
					return;
				}
				sjm[y][i]=ss;
			}			
		}
		else{
			return;
		}
		j=i;
		ss++;
	}
	return;
}
long long dsh(long long l,long long r,long long y,long long las){
	if(sjm[l][r]==0){
		return 0;
	}
	if(y==r&&las==sjm[l][r]){
		return 1;
	}
	if(y>r){
		return 0;
	}
	if(las>sjm[l][r]){
		return 0;
	}
	long long sum=0;
	for(long long i=y;x[i]-x[y]<=d;i++){
		sum+=dsh(l,r,i,las+1);
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		sum=0;
		memset(sjm,0,sizeof(sjm));
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		x[n+1]=0xffffff;
		x[n+2]=0xffffff;
		for(long long i=1;i<=n-1;i++){
			find(i);
		} 
//		for(long long i=1;i<=n-1;i++){
//			for(long long j=i+1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<sjm[i][j]<<endl;
//			}
//		}
		for(long long i=1;i<=n-1;i++){
			for(long long j=i+1;j<=n;j++){
				if(dsh(i,j,i,0)==2){
//					cout<<i<<"-"<<j<<endl;
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


/*

*/
