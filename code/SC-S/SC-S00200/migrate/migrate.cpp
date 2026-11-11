#include<bits/stdc++.h>
using namespace std;
int c,t;
int  num(){
	vector<int> x;
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int nu=0;
	for(int i=3;i<=n;i++){
		int a=1;
		vector<int> rl;
		for(int j=1;j<i;j++){
			int l;
			l=x[i]-x[j];
			if(l<=d){
				rl[a]=l;
				a++;
			}
		}
		for(int k=a;k>=1;k--)
		{
			for(int m=1;m<k-1;m++){
				if(rl[k]==rl[m]){
					nu++;
				}
			}	
		}
		
	}
	
	return nu;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		t--;
		cout<<num()<<endl;}
	return 0;
}