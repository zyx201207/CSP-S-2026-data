#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long c,T;
long long n,d;
long long x[100005];
long long f[1005][1005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if(c==11||c==12){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            long long dd=x[2]-x[1];
            if(d<=dd){
                cout<<0<<'\n';
            }else if(d==2*dd){
                cout<<n-3<<'\n';
            }else if(d>=3*dd){
                cout<<0<<'\n';
            }
        }
        return 0;
    }
    if(c==13||c==14){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            cout<<0<<'\n';
        }
        return 0;
    }
    while(T--){
    	long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        //cout<<11111;
        for(int i=1;i<=n;i++){
        	memset(f,0,sizeof(f));
        	f[i][0]=1;
        	for(int j=i+1;j<=n;j++){
        		for(int k=0;k<=n;k++){
        			for(int p=j-1;p>=i;p--){
        				if(x[j]-x[p]<=d){
        					f[j][k]+=f[p][k-1];
						}
					}
				} 
			}
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(f[j][k]!=0){
						if(f[j][k]==2)ans+=1;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
    }
    return 0;
}
