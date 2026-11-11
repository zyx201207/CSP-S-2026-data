#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>a(n);
	long long p=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		p=max(p,a[i]);
	}
	long long ws=0;
	while(p>0){
		p=p/2;
		ws++;
	}
	vector<vector<bool> >ejz(n,vector<bool>(ws));
	vector<bool>zero(ws,0);
	vector<long long>spd(ws,0);
	for(long long i=0;i<n;i++){
		long long x=a[i];
		long long y=0;
		while(x>0){
			ejz[i][y]=x%2;
			y++;
			x=x/2;
		}
	}
	long long res=0;
	for(long long j=ws-1;j>=0;j--){
		long long tt=0;
		for(long long i=0;i<n;i++){
			tt+=ejz[i][j];
		}
		if(tt<m){
			continue;
		}
		else{
			res+=1<<j;
			for(int i=0;i<n;i++){
				if(ejz[i][j]==0){
					ejz[i]=zero;
				}
			}
		}
	}
	
	cout<<res<<endl;
	return 0;
	
}
