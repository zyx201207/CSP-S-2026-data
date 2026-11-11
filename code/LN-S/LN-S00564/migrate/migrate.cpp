#include<bits/stdc++.h>
using namespace std;
const int N=2e5+6;
int dao[N],dist[N],ans[N];
int c,T;
int main(){
	freopen("migrate1.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
			cin>>dao[i];
		}
		fill(dist,dist+N,INT_MIN);
		dist[1]=0;
		
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(d>=(dao[i]-dao[j])){
					//cout<<114514;
					if(dist[i]<dao[i]-dao[j]){
						ans[i]++;}
					else{
						ans[i]=0;
						dist[i]=dao[i]-dao[j];}
				}
				
			}
		}
		int k=0;
		for(int i=1;i<=n;i++){if(ans[i]==2){ k++;}cout<<dist[i]<<' ';}
		cout<<k<<'\n';
    }
    return 0;
}

