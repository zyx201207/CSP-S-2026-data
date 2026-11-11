#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int j[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=0,k=0;k<=4;k++,i++){
        j[k]=i;
        if(i==2) i+=10; 
    }
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(abs(j[s1[2]-'A']-j[s2[2]-'A'])<=5){
                cout<<1;
                if(abs(j[s1[2]-'A']-j[s2[2]-'A'])==1) cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
/*
锐评现在的信息学奥赛教学体系：
老师夸夸其谈，结果连解压缩都没教给同学们……
老师夸夸其谈，结果学生上了考场不会用freopen……
老师还在夸夸其谈，结果在考场上同学不好好用软件把电脑炸了还说是设备的问题……
真心建议好好优化一下现在的信奥教学体系
好的老师真的很好，差的老师徒有其表
（祝贺看到这些话的OIer全部省一！！！）
（再祝贺所有OIer暴力满分，打表满分！！！）
（还有，我的洛谷叫I_am_a_koi，壶关一下，谢谢）
（再问一嘴，有人玩florr吗）
9:59补：那个把电脑玩炸的小孩哥又把键盘玩炸了，四个监考围着他找了五分钟问题，结果啥都没找出
*/