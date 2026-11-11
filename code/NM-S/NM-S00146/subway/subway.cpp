#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k,id;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	struct station{
        int id;
        int time;
	};
	struct line{
        int id;
        int times[25];
	};
	cin>>c>>n>>m>>d>>q;

	line lines[n];
	station stations[m];

	for(int i=1;i<=m;i++){
        stations[i].id=i;
        cin>>stations[i].time;
	}

    for(int l=1;l<=n;l++){
        lines[l].id=l;
        cin>>k;
        for(int s=1;s<=k;s++){
            cin>>id;
            cin>>lines[l].times[id];
        }
    }


	return 0;
}

