#include <bits/stdc++.h>
using namespace std;
int gra;
int timeuse[505050];
int timeuse2[505050];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(timeuse2,0x3f,sizeof(timeuse2));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>timeuse[i];
	}
	for(int i=1;i<=n;i++){
		int stations;
		cin>>stations;
		for(int j=1;j<=stations;j++){
			int timeadd;
			cin>>gra>>timeadd;
			if(timeuse2[j]==0x3f3f3f3f){
				timeuse2[j]=0;
			}
			timeuse2[j]+=timeadd;
		}
	}
	sort(timeuse2+1,timeuse2+m+1);
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		cout<<timeuse[st]+timeuse2[1]<<timeuse[ed]<<endl;
	}
	return 0;
} 
