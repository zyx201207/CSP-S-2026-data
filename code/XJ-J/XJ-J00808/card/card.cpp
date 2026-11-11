#include <bits/stdc++.h> 
using namespace std;
const int N=1e5+9;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[N],msm[N]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		int ms[N]={0};
		for(int i=x;i<=n;i++){
			ms[a[i]]++;
			if(ms[a[i]]>1){
				for(int j=1;j<i;j++)ms[j]=0;
				ms[a[i]]++;
			}
		}
		for(int o=1;o<=m;o++){
			msm[o]+=ms[o];
		}
	}
	for(int i=1;i<=m;i++){
		while(msm[i]==0)i++;
		cout<<msm[i]<<' '; 
	}
	
	return 0;
} 
