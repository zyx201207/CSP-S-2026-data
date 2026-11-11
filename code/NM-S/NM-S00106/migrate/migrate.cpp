#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,x;
int s[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		cin>>m>>x;
		for(int i=0;i<m;i++){
			cin>>s[i];
		}
		int idx=-1,idx2=-1;
		if(s[m-1]){
			for(int i=0;i<m;i++){
				if(s[i]>=x*3){
					idx2=i;
					break;
				}
			}
		}
		for(int j=0;j<idx2;j++){
			if(s[j]-s[0]>x){
				idx=j;
				break;
			}
		}

		if(idx==-1){
			cout<<0;
		}

	}


	return 0;
}
