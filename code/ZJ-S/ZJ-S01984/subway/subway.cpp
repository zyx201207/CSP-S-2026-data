#include<bits/stdc++.h>
using namespace std;
int k[100][100][2];
int j[100][2];

int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>  lst(m);
	for(int i=0;i<m;i++){
		cin>>lst[i];
	}
    int nu=0;
    int ct=0;
	for(int i=0;i<n;i++){
		cin>>nu;
		for(int j=0;j<nu;j++){
			cin>>k[ct][i][0]>>k[ct][i][1];
		}
		ct=ct+1;
	}
    for(int i=0;i<q;i++){
    	cin>>j[i][0]>>j[i][1];
	}
	for(int i=0;i<q;i++){
		int ans=0;
		int q=j[i][0];
    	int p=j[i][1];
    	ans=ans+q+p;
		for(int j=0;j<ct;j++){
			for(int l=0;l<n;l++){
				if(k[j][l][0]==q){
					ans=ans+k[j][l][1];
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


