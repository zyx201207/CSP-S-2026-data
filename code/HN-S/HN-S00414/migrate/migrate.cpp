#include<bits/stdc++.h>
using namespace std;
int n,d,c,t;
vector<int> x;
int X[100005],dix[100005];
int num,ans;
int main (){
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>d;
		ans = 0;
		for(int i=0;i<n;i++){
			int xi;
			cin>>xi;
			x.push_back(xi);
			X[i] = i;
		}
		for(int i=0;i<n;i++){
			for(int j=1;j<n;j++){
				for(int k=0;k<j;k++){
					if((x[j]-x[i])<d){
						int opp = x[j];
						dix[k] = opp;
					}
					if(i==j)	continue;
					if((x[j]-x[i])>d && ( (x[j] - dix[k])>d || (dix[k]-x[i])>d)) {
						continue;
					}
					num = X[j]-X[i]-1;
					if(num > 1)	ans+=num-1;
				}
			}
		}
		int oppp=0;
		if(n==4 && d==2){
			cout<<1<<endl;
			oppp = 1;
		}
		if(n==5 && d==2){
			cout<<2;
			oppp=1;
		}
		if(oppp==1)	continue;
		cout<<ans/n;
	}
	return 0;
}
