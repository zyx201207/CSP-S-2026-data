#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,sum,ans;
char b;
bool jo;
vector<int>tt;
vector<char>ch;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i=0;i<n;i++){
        cin >>a>>b;
        sum+=a;
        if(i>0&&b==ch[i-1])tt[i-1]+=a,i--,n--;
        else {
        tt.push_back(a);
        ch.push_back(b);
        }
    }
    jo=sum%2;
    sum/=2;
    int pl=n-1;
    for(int i=0;i<n;i++){
        if(sum>tt[i]){
            int tem=tt[i];
            while(tem>=tt[pl]){
                if(ch[i]!=ch[pl])ans+=tt[pl];
                tem-=tt[pl];
                pl--;
            }
            if(ch[i]!=ch[pl])ans+=tem;
            tt[pl]-=tem;
            sum-=tt[i];
        }
        else {
            int oth=tt[i]-sum-jo;
            if(sum==oth){
                break;
            }
            else if(sum>oth){
                int tem=sum-oth;
                while(pl>i){
                    if(ch[pl]!=ch[i])ans+=tt[pl];
                    pl--;
                }
                break;
            }
            else {
                int tem=oth-sum,ti=i;
                while(tem>=tt[ti]){
                    if(ch[ti]!=ch[i])ans+=tt[ti];
                    ti--;
                }
                if(ch[ti]!=ch[i])ans+=tem;
                break;
            }
        }
    }
    cout <<ans;
    return 0;
}
