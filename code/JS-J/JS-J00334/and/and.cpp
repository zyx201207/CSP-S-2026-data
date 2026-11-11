#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[200010],cnt,numm[4],maxxx;
int num[30];
void dfs(int x,int en){
    //if (m-en < x) return;
    if (x == 0){
        int nt = num[0];
        //cout<<num[0]<<" ";
        for(int i=1;i<m;i++){
        //    cout<<num[i]<<" ";
            nt &= num[i];
        }
        //cout<<endl;
        maxxx = max(maxxx,nt);
        return;
    }
    for(int i=en;i<n;i++){
        //cout<<"%"<<endl;
        num[m-x] = b[i];
        dfs(x-1,i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if (n == m){
        cin>>a;
        cnt = a;
        for(int i=1;i<n;i++){
            cin>>a;
            cnt &= a;
        }
        cout<<cnt;
        return 0;
    }
    else if (m == 1){
        int maxx = -1;
        for(int i=0;i<n;i++){
            cin>>a;
            maxx = max(maxx,a);
        }
        cout<<maxx;
        return 0;
    }
    else if(m == 2){
        for(int i=0;i<n;i++) cin>>b[i];
        int maxx = -1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                maxx = max(maxx,b[i]&b[j]);
            }
        }
        cout<<maxx;
        return 0;
    }
    else if(m == n-1){
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++){
            if (i == 0) cnt = b[1];
            else cnt = b[0];
            for(int j=1;j<n;j++){
                if (j != i){
                    cnt &= b[j];
                }
            }
        }
        cout<<cnt;
        return 0;
    }
    int maxx = -1;
    for(int i=0;i<n;i++){
        cin>>b[i];
        maxx = max(maxx,b[i]);
        if (b[i] <= 3) numm[b[i]]++;
    }
    if (maxx == 3){
        if (numm[3] >= m) {
            cout<<3;
            return 0;
        }
        else if(numm[3] + numm[2] >= m){
            cout<<2;
            return 0;
        }
        else if(numm[3] + numm[1] >= m){
            cout<<1;
            return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }
    else if(maxx == 2){
        if(numm[2] >= m){
            cout<<2;
            return 0;
        }
        else if(numm[1] >= m){
            cout<<1;
            return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }
    dfs(m,0);
    cout<<maxxx;
    return 0;
}
//hao3nan2
//shu4jv4da4de0gan3jve2dou1guo4bu4liao3
//gao3yi4dian3te4pan4ba0
//neng2pian4yi4dian3shi4yi4dian3
//hai3you3hao3duo1zuo4ye4a0
// xjy bu4zhi4zhe4me0duo1jvan4zi0

//zan2zhe4yang4zuo4zhen1de0hui4shang4mi2huo2xing2wei2da4shang3ma0
