#include<bits/stdc++.h>
using namespace std;
int w[40],n,m,a[200010],ans=0;
bitset<200010> q;
vector<int> r[40];
void insect(int x,int f,int y){
	int i=0;
	while(x){
		if(f==1)w[i]=w[i]+(x%2);
		else w[i]=w[i]-(x%2);
		if(f&&x%2)r[i].push_back(y);
		x/=2;i++;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		insect(a[i],1,i);
	}
	for(int i=33;i>=0;i--){
		if(w[i]<m)continue;
		ans+=pow(2,i);
		int s=0;
		for(int j=0;j<r[i].size();j++){
			for(int k=s+1;k<r[i][j];k++)
				if(q[k]==0){
					insect(a[k],0,k);
					q[k]=1;
					}
			s=r[i][j];
		}
	}
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
