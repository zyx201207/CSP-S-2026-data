#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long W[50005];
long long dis[15005][15005];
long long j[50005],t[50005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dis[i][j]=INT_MAX/2;
            if(i==j)
                dis[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int s=1;s<=k;s++){
			cin>>j[s]>>t[s];
		}
        for(int s=1;s<=k;s++){
            for(int l=1;l<=k;l++){
                if(s==l)
                continue;
                dis[j[s]][j[l]]=t[s]+t[l];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i==j)
            continue;
            for(int k=1;k<=m;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
            //cout<<dis[i][j]<<' ';
        }
        //cout<<endl;
    }
    while(q--){
        long long l,r;
        cin>>l>>r;
        cout<<dis[l][r]+W[l]+W[r]<<endl;
    }
    return 0;
}
