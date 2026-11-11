#include<bits/stdc++.h>
using namespace std;
struct sadness{
    int id,num;
};
int a[200005];
bool cmp(sadness d,sadness p){
    return d.num>p.num;
}
bool cmp2(int sad,int ness){
    return sad>ness;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
     freopen("and.in","r",stdin);
     freopen("and.out","w",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int cnt=-1;
        for(int i=1;i<=n;i++) cnt=max(cnt,a[i]);
        cout<<cnt;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else if(m==n){
        int cnt=a[1];
        for(int i=2;i<=n;i++) cnt=cnt&a[i];
        cout<<cnt;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else if(m==2){
        int cnt=a[1]&a[2];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                cnt=max(cnt,a[i]&a[j]);
            }
        }
    cout<<cnt;
       fclose(stdin);
       fclose(stdout);
    return 0;
    }
    else if(m==n-1){
        int cnt=a[1],sum=0;
        for(int i=1;i<=n;i++){
            if(i==1) cnt=a[2];
            for(int j=1;j<=n;j++){
                if(i!=j) cnt&=a[j];
            }
            sum=max(sum,cnt);
        }
        cout<<sum;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else{
        vector<sadness> x(n+5);
        for(int i=1;i<=n;i++){
            int f=a[i];
            x[i].id=i;
            while(f){
               x[i].num+=f&1;
               f/=2;
            }
        }
        sort(x.begin(),x.end(),cmp);
        int cnt=a[x[1].id];
        for(int i=2;i<=m;i++){
            cnt&=a[x[i].id];
        }
        sort(a+1,a+n+1,cmp2);
        int sum=a[1];
        for(int i=2;i<=m;i++) sum&=a[i];
        cout<<max(cnt,sum);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
}//写完这个代码 本人心底也是一种心酸 很无奈 但愿能多得点分吧 电脑运行不到 因为机器是无情的 但我想看见它的你 是满心憧憬的... 要求不多 20就行.....^v^ ^V^ ^v^
