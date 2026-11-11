#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,before_num[maxn],ans;
long long m,num1,a[maxn],cut[maxn];
priority_queue<long long,vector<long long>,greater<long long>> qd;
void slove(){
    int last=qd.top();
    int last_choice =0;
    int cnt=0;
    while(!qd.empty()){
        int num=qd.top();

        before_num[cnt+1]++;
        cnt++;
        before_num[cnt+1]=before_num[cnt];
        a[cnt] = a[cnt-1]+(num-last)*before_num[cnt-1];

        qd.pop();

        while(!qd.empty()){
            if(last!=qd.top()) break;
            before_num[cnt+1]++;

            qd.pop();
        }
        cut[cnt]=cut[cnt-1] + num - last;
        int now_m = a[cnt] - a[last_choice] - before_num[last_choice]*(num-last);

        while(now_m>m){

            last_choice++;
            now_m = a[cnt] - a[last_choice] - before_num[last_choice]*(cut[cnt]-cut[last_choice]);

        }

        int now_ans=0;
        if(last_choice != 0){
            now_ans = before_num[cnt] - before_num[last_choice] +(m-now_m)/(cut[cnt]-cut[last_choice]);
            ans = max(ans,now_ans);

        }
        else{
            ans = before_num[cnt];
        }
        last = num;
    }
    printf("%d",ans);
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&num1);
        qd.push(num1);
    }
    slove();

    return 0;
}
