#include <bits/stdc++.h>
using namespace std;

struct point{
    int to[41],time[20],num=0,line[20];
}pt[500001];
int x,y;
int best[500001];
int findline(int a,int b){
    for(int i=0;i<pt[a].num;i++){
        if(pt[a].line[i]==b)return i;
    }
    return -1;
}
void dfs(int pos,int curtime,bool gate,int line1){
    //cout<<(gate? 1:0)<<" "<<pos<<" "<<line1<<" "<<curtime<<endl;


    if(!gate){//chu zhan jiu shan diao
        if(best[pos]>curtime-pt[pos].time[findline(pos,line1)])best[pos]=curtime-pt[pos].time[findline(pos,line1)];
        if(line1!=-1)return;
    }if(pos==y-1&&!gate)return;
    if(line1==-1){
        for(int i=0;i<pt[pos].num;i++){
            int linechosen=pt[pos].line[i];
            dfs(pos,curtime+pt[pos].time[i],true,linechosen);//di yi ci
        }
        return;
    }

    //jin xing chu zhan
    for(int i=0;i<pt[pos].num;i++){//zuo di tie
        /*
        int nxt1=pt[pos].to[2*i],nxt2=pt[pos].to[2*i+1],addtime1=pt[nxt1].time[findline(nxt1,line1)]+curtime,addtime2=pt[nxt2].time[findline(nxt2,line1)]+curtime;
        if(best[nxt1]>addtime1)dfs(nxt1,addtime1,true,line1);
        if(best[nxt2]>addtime2)dfs(nxt2,addtime2,true,line1);
        */
        int linechosen=pt[pos].line[i];
        if(linechosen==line1){
            int nxt1=pt[pos].to[2*i],nxt2=pt[pos].to[2*i+1],addtime1=pt[nxt1].time[findline(nxt1,line1)]+curtime,addtime2=pt[nxt2].time[findline(nxt2,line1)]+curtime;
        if((best[nxt1]>addtime1)&&nxt1!=-1)dfs(nxt1,addtime1,true,line1);
        if(best[nxt2]>(addtime2)&&nxt2!=-1)dfs(nxt2,addtime2,true,line1);
        }
        else{
            int nxt1=pt[pos].to[2*i],nxt2=pt[pos].to[2*i+1];
            int addtime1=curtime+pt[pos].time[i]+pt[nxt1].time[findline(nxt1,linechosen)],addtime2=curtime+pt[pos].time[i]+pt[nxt2].time[findline(nxt2,linechosen)];
            if(best[nxt1]>(addtime1)&&nxt1!=-1)dfs(nxt1,addtime1,true,linechosen);
            if(best[nxt2]>(addtime2)&&nxt2!=-1)dfs(nxt2,addtime2,true,linechosen);
        }

    }
int lineid=findline(pos,line1);
    if(curtime+pt[pos].time[lineid]<best[pos])dfs(pos,curtime+pt[pos].time[lineid],false,line1);
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)best[i]=100001;
    int w[m];
    //cout<<m<<" "<<m<<" "<<m<<" "<<endl;
    for(int i=0;i<m;i++)cin>>w[i];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;int aaa[x],ttt[x];
        for(int j=0;j<x;j++){
            cin>>aaa[j]>>ttt[j];aaa[j]--;
        }
        for(int j=0;j<x;j++){
                int num1=pt[aaa[j]].num;

            if(j==x-1){
                pt[aaa[j]].to[2*num1+1]=-1;pt[aaa[j]].to[2*num1]=aaa[j-1];
            }
            else if(j==0){
                pt[aaa[j]].to[2*num1+1]=aaa[j+1];pt[aaa[j]].to[2*num1]=-1;
            }
            else{
                pt[aaa[j]].to[2*num1+1]=aaa[j+1];pt[aaa[j]].to[2*num1]=aaa[j-1];
            }
            pt[aaa[j]].time[num1]=ttt[j];pt[aaa[j]].line[num1]=i;
            pt[aaa[j]].num++;
        }
    }
    /*
    for(int i=0;i<m;i++){
        cout<<"station"<<i+1<<": "<<pt[i].num<<" lines"<<endl;
        for(int j=0;j<pt[i].num;j++){
            cout<<pt[i].line[j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=0;i<q;i++){

        cin>>x>>y;
        dfs(x-1,0,false,-1);
        cout<<best[y-1]+w[x-1]+w[y-1]<<endl; //for(int i=0;i<m;i++)cout<<best[i]<<" ";
        //cout<<endl;
        for(int i=0;i<m;i++)best[i]=100001;
    }



    return 0;
}
/*
if(line1==0){
        for(int i=0;i<pt[pos].num;i++){
            if(pt[pos].to[2*i]!=-1)dddfffsss(pt[pos].to[2*i],curtime+pt[pos].time[i],true,pt[pos].line[i]);
            if(pt[pos].to[2*i+1]!=-1)dddfffsss(pt[pos].to[2*i+1],curtime+pt[pos].time[i],true,pt[pos].line[i]);
        }
    }
    for(int i=0;i<20;i++){
        if(pt[pos].line[i]==line1){
            dddfffsss(pos,curtime+pt[pos].time[i],true,67);break;
        }
    }
    for(int i=0;i<pt[pos].num;i++){
        int swl=pt[pos].line[i],nxt1=pt[pos].to[2*i],nxt2=pt[pos].to[2*i+1];
        if(swl==line1){

        }
    }
    */
