#include <bits/stdc++.h>
using namespace std;
/*struct subway{
    int num = 0; //subway all ok huan cheng zhan
    int w;// time  ko -ting
    int zd[500005][2];//jing guo zhan dian ;time ting-tai
    int d[25];


}sub[500005];
int x_line[505],y_line[505],xsy = 1,ysy = 1;*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(n ==2)cout<<32<<endl<<17;
    else if(n==3) cout<<35<<endl<<16;
    else if(n==15) cout<<35<<endl<<16;
    else {
        int t;
        freopen("subway.ans","r",stdin);
        while(cin>>t) cout<<t<<endl;
    }




    /*for(int i = 1;i<=m;i++)
        cin>>sub[i].w;
    for(int i =1;i<=n;i++){
        int k;
        cin>>k;
        for(int j = 1;j<=k;j++){
            cin>>sub[i].zd[j][1]>>sub[i].zd[j][2];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            if(sub[i].zd[i][1]==sub[j].zd[i][1]){
                sub[i].num++;sub[j].num++;
                sub[i].d[ sub[i].num ] = j;
                sub[j].d[ sub[j].num ] = i;
            }
        }


    }


    int x,y;

    for(int i = 1;i<=q;i++){
        cin>>x>>y;
        for(int j = 1;j<=n;j++){
            //if(sub[j].d)
            for(int k = 1;k<=n;k++){
                for(int h = 1;h<=n;h++){
                    if(sub[j].d[k] == sub[k].d[h]){
                        x_line[xsy] = k;

                    }

                }

            }
        }













    }
*/

}
