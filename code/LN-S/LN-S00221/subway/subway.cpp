#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ki,xr,yr,t2,tmi;
queue <int> p;
const int O=10000;
struct L1{
    int No[O];//该线路经过No号地铁站
    int Len[O];//该路线到No站台的距离
    int Nocnt;//共连接了几个地铁站
}r[505]/*地铁线路的链式前向星*/;
struct L2{
    int point[50000];
    int num;
    int road[25];
};
int outs[O]/*地铁站厅到站台的距离*/,mi[O],depth[O],cr[O];
L2 connect[O];//每个地铁站到的地铁站以及通过的线路
//bool used[500005];//地铁站是否完事
int print[100003];
int main(){
   freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    fill(mi+1,mi+m+1,INT_MAX);
    for(int i=1;i<=m;i++){
            scanf("%d",&outs[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&ki);
        for(int j=1;j<=ki;j++){
            scanf("%d%d",&r[i].No[j],&r[i].Len[j]);
        }
        for(int j=1;j<=ki-1;j++){
			int xk=r[i].No[j];//第i条路连接的
            connect[xk].point[++connect[xk].num]=r[i].No[j+1];
            connect[xk].road[connect[xk].num]=i;
        }
        for(int j=2;j<=ki;j++){
			int xk=r[i].No[j];//第i条路连接的
            connect[xk].point[++connect[xk].num]=r[i].No[j-1];
            connect[xk].road[connect[xk].num]=i;
        }
        r[i].Nocnt=ki;
//      for(int j=1;j<=connect[r[i].No[j]].num;j++) {//
//	printf("%d ",connect[2].point[j]);//
//		}//
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&xr,&yr);
        p.push(xr);
        mi[xr]=0;
        depth[xr]=1;
        tmi=INT_MAX;
        while(!p.empty()){
            int temp=p.front();
//            printf("temp=%d\n",temp);
            p.pop();
            for(int j=1;j<=connect[temp].num;j++){
                    t2=connect[temp].point[j];
//					printf("t2=%d ",t2);
                    depth[t2]=depth[temp]+1;
                    if(depth[t2]<=2){
                            mi[t2]=0;
                            cr[t2]=connect[temp].road[t2];
                            p.push(t2);
//                        if(mi[t2]>mi[temp]){
//                            mi[t2]=mi[temp];
//                            if(t2!=yr) p.push(t2);
                        //}
                    }else{
                        if(connect[temp].road[t2]==cr[t2]){
                           if(mi[t2]>mi[temp]){
                            mi[t2]=mi[temp];
                            cr[t2]=connect[temp].road[t2];
                            if(t2!=yr) p.push(t2);
                           }
                        }
                        else{
                            if(mi[t2]>mi[temp]+r[connect[temp].road[t2]].Len[temp]){
                                mi[t2]=mi[temp]+r[connect[temp].road[t2]].Len[temp];
                                cr[t2]=connect[temp].road[t2];
                                if(t2!=yr) p.push(t2);
                            }
                    }


                }
                if(t2==yr) tmi=min(tmi,mi[t2]);
            }
        }
        print[i]=tmi+outs[xr]+outs[yr]+r[cr[t2]].Len[t2];
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",print[i]);
    }
fclose(stdin);
   fclose(stdout);
    return 0;
}
