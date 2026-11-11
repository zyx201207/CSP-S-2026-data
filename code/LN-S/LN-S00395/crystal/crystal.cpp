#include<bits/stdc++.h>
#define int __int128
using namespace std;
int N, M;
int A[512345];



int qread(void){
    int flg = 1, c = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch=='-') flg = -flg;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        c *= 10;
        c += ch-'0';

        ch = getchar();
    }
    return flg*c;
}
void qwrite(int x){
    if(x < 0){
        putchar('-');
        qwrite(-x);
        return;
    }
    if(x < 10) {
        putchar(x+'0');
        return;
    }
    qwrite(x/10);
    putchar((x%10)+'0');
}
void qspace(void){putchar(' ');}
void qendl(void){putchar('\n');}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    //首先我们直到，当固定最大水晶后，一定优先加最近的水晶
    //哦哦哦
    //双指针
    //当最大水晶右移时
    //最小水晶一定右移

    //cin>>N>>M;
    N=qread();
    M=qread();
    for(int i = 1; i <= N; i++) A[i]=qread();//cin>>A[i];

    sort(A+1, A+1+N);

    int L = 1, dis = 0, mxAns = 0;
    for(int R = 1; R <= N; R++){
        //如果旧指针的区间大小过大
        dis += (A[R]-A[R-1])*(R-L);//加上差值
        //如果差值过大
        while(dis > M){
            dis -= (A[R]-A[L]);
            L++;
        }

        mxAns = max(mxAns, R-L+1);
    }

    //cout<<mxAns;
    qwrite(mxAns);
}
//One G memory!? qwq
//Wait for duipai:)
