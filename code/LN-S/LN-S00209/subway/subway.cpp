#include<iostream>
using namespace std;
int c,n,m,d,q;
int a[500][500],t[500][500];
int w[1001];
int qw[1001];
int k[1001];
struct n1{
    int kx,tx;
}qq[1001];
struct n2{
    int ky,ty;
}ww[1001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
            qw[a[i][j]]++;
        }
    }
    for(int ii=1;ii<=q;ii++){
        int x,y;
        cin >> x >> y;
        int sum=0;
        sum+=w[x]+w[y];
        if(n==1){
            for(int j=1;j<=k[1];j++){
                if(a[1][j]==x||a[1][j]==y){
                    sum+=t[1][j];
                }
            }
            cout << sum;
        }else{
            int xq=0,yq=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=k[i];j++){
                    if(a[i][j]==x){
                        xq++;
                        qq[xq].kx=i;
                        qq[xq].tx=t[i][j];
                    }
                    if(a[i][j]==y){
                        yq++;
                        ww[yq].ky=i;
                        ww[yq].ty=t[i][j];
                    }
                }
            }
            int num=99999999;
            for(int i=1;i<=xq;i++){
                for(int j=1;j<=yq;j++){
                    int su=qq[i].tx+ww[j].ty;
                    if(qq[i].kx==ww[j].ky){

                    }else{
                        int yu=99999999,fa=0;
                        for(int fi=1;fi<=k[qq[i].kx];fi++){
                                int er=0;
                            if(qw[a[qq[i].kx][fi]]>0){
                                for(int fii=1;fii<=k[ww[j].ky];fii++){
                            if(a[qq[i].kx][fi]==a[ww[j].ky][fii]){
                                er=t[qq[i].kx][fi]+t[ww[j].ky][fii];
                                fa=1;
                                break;
                            }
                        }
                            }
                            if(fa==1){
                                yu=min(yu,er);
                            }
                        }
                        su+=yu;
                    }
                    num=min(su,num);
                }
            }
            cout << num;
        }
        cout << endl;
    }
}
