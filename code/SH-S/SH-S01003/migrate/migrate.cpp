#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[100005],end,min_ci_shu=1e9,s=0;
int fly(int where,int ci_shu,int end){
	if (where==end){
		if (min_ci_shu>ci_shu){
			min_ci_shu=ci_shu;
		}
		if (ci_shu==min_ci_shu){
			s++;
		}
	}
	if (where>end){
		return 0;
	}
	if (ci_shu>min_ci_shu){
		return 0;
	}
	int where2=where+1;
	while(x[where2]-x[where]<=d and where2<=n){
	//	cout<<where<<where2<<x[where]<<x[where2]<<endl;
		where2++;
	}
	//cout<<where2<<endl;
	for (int i=where2-1;i>=where+1;i--){
		//cout<<i<<':'<<ci_shu+1<<endl;
		fly(i,ci_shu+1,end);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int k=1;k<=t;k++){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				s=0;
				min_ci_shu=1e9;
				//cout<<"AAAAA"<<i<<j<<endl;
				fly(i,0,j);
				//cout<<"BBBBB"<<s<<endl;
				if (s==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
