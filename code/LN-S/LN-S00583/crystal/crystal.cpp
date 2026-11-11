#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
long long n;
long long m,ans=0;
long long cnt=0;
long long sum=0;
//5 10
//1 2 3 4 5
void dfs(int x,long long cnt,long long sum){
    if(sum>n){
        return;
    }

    long long cost=abs(a[x]*(sum)-cnt);
    if(x==1)cost=0;
    //cout<<"Now cost:"<<cost<<endl;
    if(cost<=m){
        ans=max(ans,sum);
        //cout<<"Now choice:"<<x<<" "<<"Now ans:"<<ans<<endl;
    }
    if(cost>m){
        return;
    }
    if(x==n){
        ans=max(ans,sum);
        return;
    }
    for(long long i=x+1;i<=n;i++){
        //cout<<"Now toatl Choice:"<<cnt+a[i]<<endl;
        //cout<<"Now choice number:"<<sum+1<<endl;
        dfs(i,cnt+a[i],sum+1);//选择下一个
    }
    return;
}// TLE QAQ!!!!!
bool vis[N];
void bfs(){
    queue<long long> q;
    q.push(a[1]);//将第一个元素入队
    vis[1]=1;//标记本元素
    sum=1;//选了一个
    cnt=q.front();//目前的总和
    int v=2;
    long long cost=abs(a[1]*sum-cnt);//计算花费
    while(!q.empty()){
        int h=q.front();//拿出队头
        q.pop();//弹出
        cost=h*sum-cnt;//计算花费
        //cout<<"Now Cost:"<<cost<<endl;
        if(cost<=m){
            ans=min(n,max(ans,sum));//更新答案
            //cout<<"Now ans:"<<ans<<endl;
        }
        if(cost<0){
            return;
        }
        if(cost>m){//如果花费过大
           while(cost>=m){
            cnt-=q.front();
            long long he=q.front();
            cost=abs(he*sum-cnt);
            //cout<<"Now cost:"<<cost<<endl;
            sum--;
            //cout<<"Now sum:"<<sum<<endl;
            q.pop();//弹出直到花费可以接受
           }
        }
        q.push(a[v++]);
        sum++;
        cnt+=a[v-1];
    }
}
int main(){
    //freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        /*
        if(i==2){
            gongcha=a[i]-a[i-1];
        }
        if(i>2){
            if((a[i]-a[i-1])!=gongcha){
                gongcha=-1;
            }
        }
        if(a[i]!=i){
            A=0;
        }
    }
    if(A){
        for(int i=1;i<=n;i++){
            if(i*(i+1)/2==m){
                ans=i+1;
            }
        }
    }else if(gongcha!=-1){
        for(int i=1;i<=n;i++){
            int xiangshu=((a[i]-a[1])/gongcha)+1;
            if((((a[1]+a[i])*xiangshu))/2-a[1] == m){
                ans=xiangshu+1;
            }
        }
    }
    if(ans!=0){
        cout<<ans<<endl;
    }else{*/
    }
    sort(a,a+n);
    ans=0;
    //dfs(1,a[1],1);
    bfs();
    cout<<ans<<endl;
    return 0;
}
/*
5 6
2 4 6 8 10
7 9
1 1 1 3 3 3 3
*/
