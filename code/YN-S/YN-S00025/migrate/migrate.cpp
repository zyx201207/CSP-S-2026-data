// author fkxr lg uid 995934
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define in cin
#define out cout
#define mset(x,k) memset(x,k,sizeof(x))
using pii=pair<int,int>;
namespace MYcode{
    const int N=2e6+5;
    int a[N];int n,d;
    // bool chk(int s,int t){
    //     if(s==t)return 1;
    //                 vector<int>p;p.push_back(s);
    //                 bool flag=1;
    //                 for(int i=s+1;i<=n;){
    //                     if(a[i]-a[p.back()]>d){
    //                         if(p.back()==i-1){
    //                             flag=0;
    //                             break;
    //                         }p.push_back(min(i-1,t));
    //                     }else i++;
    //                     if(p.back()==t)break;
    //                 }flag&=(p.back()==t);
    //                 if(flag){
    //                     //for(auto i:p)out<<i<<" ";out<<"\n";
    //                     int cnt=0;
    //                     for(int i=0;i+2<p.size();i++){
    //                         int x=p[i],y=p[i+2];
    //                         int k=0;
    //                         for(int j=x+1;j<y;j++)
    //                             if(a[j]-a[x]<=d&&a[y]-a[j]<=d){
    //                                 k++;
    //                                 if(k>=3){
    //                                     flag=0;
    //                                     break;
    //                                 }
    //                             }
    //                         if(k==2)++cnt;
    //                         if(cnt>0)break;
    //                     }//out<<cnt<<"cccc\n";
    //                     flag&=(cnt==0);
    //                 }return flag;
    // }int e[305],b[305];
    void work(){
        int c,T;in>>c>>T;
        for(;T--;){
            in>>n>>d;
            for(int i=1;i<=n;i++)in>>a[i];
            //nature A:
            if(n<=3){
                out<<"0\n";
                continue;
            }
            if((c>=11&&c<=12)){
                int k=a[2]-a[1];
                if(k>=d){
                    out<<"0\n";
                }else{
                    int len=d/k*2;
                    out<<max(0ll,n-len+1)<<"\n";
                }continue;
            }if(c>=13&&c<=14){
                int ans=0;
                for(int i=1;i+3<=n;i++){
                    if(a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d&&a[i+2]-a[i]<=d){
                        ++ans;
                    }
                }out<<ans<<"\n";
                continue;
            }
            // 1~10:
            n++;a[n]=a[n-1]+d+1;
            int ans=0;
            for(int s=1;s<n;s++){
                vector<int>p;p.push_back(s);
                for(int t=s+1;t<n;t++){
                    if(p.size()>1)p.pop_back();
                    int tmp=p.back();
                    if(p.size()>1)p.pop_back();
                    bool flag=1;
                    for(int i=tmp+1;i<=n;){
                        if(a[i]-a[p.back()]>d){
                            if(p.back()==i-1){
                                flag=0;
                                break;
                            }p.push_back(min(i-1,t));
                        }else i++;
                        if(p.back()==t)break;
                    }flag&=(p.back()==t);
                    if(!flag)break;
                    if(flag){
                        //for(auto i:p)out<<i<<" ";out<<"\n";
                        int cnt=0;
                        for(int i=0;i+2<p.size();i++){
                            int x=p[i],y=p[i+2];
                            int k=0;
                            for(int j=max(x+1,p[i+1]-2);j<min(y,p[i+1]+3);j++)
                                if(a[j]-a[x]<=d&&a[y]-a[j]<=d){
                                    k++;
                                    if(k>=3){
                                        flag=0;
                                        break;
                                    }
                                }
                            if(k==2)++cnt;
                            if(cnt>1)break;
                        }//out<<cnt<<"cccc\n";
                        flag&=(cnt==1);
                    }if(flag)ans++;
                    //out<<flag<<" ";
                    //if(flag){for(auto i:p)out<<i<<" ";out<<"\n";}
                }//out<<"\n";
            }
            out<<ans<<"\n";
        }
    }
}signed main(){
    string pid="migrate";
    freopen((pid+".in").c_str(),"r",stdin);
    freopen((pid+".out").c_str(),"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    MYcode::work();
    return 0;
}
/*

*/