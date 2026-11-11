#include<bits/stdc++.h>
const int N=5e5+10,M=3e5+10;
using namespace std;
int num[N],mem[M],cnt[N],oldsixxie[N],n,m;
int main(){
    freopen("card3.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++){
        memset(mem,0,sizeof(mem));
        memset(oldsixxie,0,sizeof(oldsixxie));
        int k=1;
        for(int j=i;j<=n;j++,k++){
            if(mem[num[j]]&&mem[num[j]]<k) k=mem[num[j]];
            else oldsixxie[k]=num[j],mem[num[j]]=k;
        }
        for(int i=1;i<k;i++) cnt[oldsixxie[i]]++;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
/*
初三了，现在连J的题目也不会做了
是时候退役了
回望五年信奥路
上课打过游戏、看过油管
但好像真的没有特别认真的上过哪怕一堂课
现在想想真有点后悔啊
今天来考试看到了已经一年没去上课的培训机构
那个之前的老师还递给我一根士力架
心中的悔恨又涌上心头
但
事情发生了就是发生了
人生注定无法重来
学了这么多年C++
在以后的人生路上总会有所帮助的吧
以前我总是不理解那些退役选手眼中的落寞
甚至还嘲笑过
结果现在我却要成为其中的一员了
真是讽刺啊
再见，CSP-J/S
你好，2027中考
再见，信奥
你好，文化课
（送给每一位退役选手“长风破浪会有时，直挂云帆济沧海”）
*/