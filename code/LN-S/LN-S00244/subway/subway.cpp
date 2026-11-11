#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,出行计划数
int mt[N],ki[N],line[510][510],dp[510][510];
struct node{
    int a[N],t[N],l=0;
}km[N];
struct aa{
    int x,y,xl[510],yl[510],xls=0,yls=0;
}kq[100010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		cin>>mt[i];
	}
    for(int i=1;i<=n;i++){
        cin>>ki[i];
        cin>>km[i].a[km[i].l+1]>>km[i].t[km[i].l+1];
        km[i].l++;
    }
    for(int i=1;i<=q;i++){
        cin>>kq[i].x>>kq[i].y;
        for(int j=1;j<=n;j++){
            for(int ja=1;ja<=ki[j];ja++){
                if(kq[i].x==km[j].a[ja]){
                    kq[i].xl[kq[i].xls++]=j;
                    cout<<"YES";
                }
            }
        }
        kq[i].xls--;
        cout<<"abb"<<kq[i].xls<<' ';
        for(int j=1;j<=n;j++){
            for(int ja=1;ja<=ki[j];ja++){
                if(kq[i].y==km[j].a[ja]){
                    kq[i].yl[kq[i].yls++]=j;
                }
            }
        }
        kq[i].yls--;
        cout<<"abc"<<kq[i].yls<<' ';
    }
    memset(line,0x3f,sizeof(line));
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        line[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int ia=1;ia<=ki[i];ia++){
                for(int ja=1;ja<=ki[j];ja++){
                    if(km[ia].a==km[ja].a){
                        line[i][j]=min(line[i][j],km[i].t[ia]+km[j].t[ja]);
                        line[j][i]=line[i][j];
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=line[i][j];
		}
	}
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    dp[j][i]=dp[i][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=q;i++){
        for(int j=1;j<=kq[i].xls;j++){
            cout<<kq[i].xl[j]<<endl;
        }
        for(int l=1;l<=kq[i].yls;l++){
			cout<<kq[i].yl[l]<<endl;
        }
    }
    for(int i=1;i<=q;i++){
        int ans=0x3f3f3f3f;
        int x=kq[i].x;
        int y=kq[i].y;
        for(int j=1;j<=kq[i].xls;j++){
            for(int l=1;l<=kq[i].yls;l++){
				cout<<endl<<mt[kq[i].x]+mt[kq[i].y];//+dp[kq[i].x][kq[i].y]+km[kq[i].xl[j]].t+km[kq[i].yl[l]].t<<endl;
				int kmi=kq[i].xl[j],kmj=kq[i].yl[l];
                ans=min(ans,mt[x]+mt[y]+dp[x][y]+km[kmi].t[x]+km[kmj].t[y]);
            }
        }
        cout<<endl<<ans<<endl;
    }
    return 0;
}
