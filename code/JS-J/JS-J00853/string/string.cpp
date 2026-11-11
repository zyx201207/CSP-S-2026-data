#include<bits/stdc++.h>
using namespace std;
struct sums{
    char word;
    int sum;
};
int n;
int a[200005];
long long L=0,ans=0;
string s;
char s1[505];
char c[200005];
sums t[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        //for(int j=1;j<=a[i];j++) s=s+c[i];
        t[i].word=c[i];
        t[i].sum=a[i];
    }
    if(L<=100010){
        for(int i=1;i<=n;i++){
            //memset(s1,c[i],a[i]);
            //s=s+s1;
            for(int j=1;j<=a[i];j++) s=s+c[i];
        }
        //cout<<s<<endl; //////////////////
        for(int i=0;i<=L/2-1;i++){
            if(s[i]==s[L-i-1]) continue;
            else ans++;
        }
        cout<<ans;
    }
    else if(L>100000){
        //cout<<s<<endl; //////////////////////
        for(int i=1;i<=n/2;i++){
            if(t[i].word==t[n-i+1].word && t[i].sum==t[n-i+1].sum) continue;
            else{
                if(t[i].word==t[n-i+1].word){
                    if(t[i].sum>t[n-i+1].sum) {
                        ans+=t[i].sum-t[n-i+1].sum;
                        int more=t[i].sum-t[n-i+1].sum;
                        if(t[n-i].sum>more) t[n-i].sum-=more;
                        else{
                            int tot=n-i+1;
                            while(more){
                                tot-=1;
                                if(more-t[tot].sum>0){
                                    more-=t[tot].sum;
                                    t[tot].sum=0;
                                }else{
                                    t[tot].sum-=more;
                                    more=0;
                                }
                            }
                            for(int i=1;i<=n;i++){
                                if(t[i].sum==0){
                                    for(int j=i+1;j<=n;j++){
                                        t[j-1].sum=t[j].sum;
                                        t[j-1].word=t[j].word;
                                    }
                                    n-=1;
                                }
                            }
                        }
                    }
                    else{
                        for(int j=n;j>=n-i+1;j--){
                            t[j].word=t[j+1].word;
                            t[j].sum=t[j+1].sum;
                        }
                        t[n-i+1].sum=t[n-i+1].sum-t[i].sum;
                        n+=1;
                    }
                }
                else if(t[i].sum==t[n-i+1].sum){
                    ans+=t[i].sum;
                    t[n-i+1].word=t[i].word;
                }
                else{
                    if(t[i].sum>t[n-i+1].sum) {
                        ans+=t[i].sum;//-t[n-i+1].sum;
                        int more=t[i].sum-t[n-i+1].sum;
                        if(t[n-i].sum>more) t[n-i].sum-=more;
                        else{
                            int tot=n-i+1;
                            while(more){
                                tot-=1;
                                if(more-t[tot].sum>0){
                                    more-=t[tot].sum;
                                    t[tot].sum=0;
                                }else{
                                    t[tot].sum-=more;
                                    more=0;
                                }
                            }
                            for(int i=1;i<=n;i++){
                                if(t[i].sum==0){
                                    for(int j=i+1;j<=n;j++){
                                        t[j-1].sum=t[j].sum;
                                        t[j-1].word=t[j].word;
                                    }
                                    n-=1;
                                }
                            }
                        }
                    }
                    //
                    else{
                        ans+=t[i].sum;
                        for(int j=n;j>=n-i+1;j--){
                            t[j].word=t[j+1].word;
                            t[j].sum=t[j+1].sum;
                        }
                        t[n-i+1].sum=t[n-i+1].sum-t[i].sum;
                        n+=1;
                    }
                }
            }
        }
        cout<<ans;
    }
    
    return 0;
}