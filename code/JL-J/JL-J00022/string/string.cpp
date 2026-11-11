#include<bits/stdc++.h>
using namespace std;
int top=0;
pair<long long,char> a[200010],b[200010];
long long ans=0,cnt=0,num=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        ans+=a[i].first;
    }
    for(int i=1;i<=n;i++){
        if(cnt+a[i].first<=ans/2+ans%2){
            b[++top]=a[i];
            cnt+=a[i].first;
        }
        else if(cnt>=ans/2+ans%2){
            while(a[i].first>=b[top].first&&top!=0){
                if(a[i].second!=b[top].second){
                    num+=b[top].first;
                }
                a[i].first-=b[top].first;
                top--;
            }
            if(a[i].second!=b[top].second){
                num+=a[i].first;
            }
            b[top].first-=a[i].first;
        }
        else{
            int x=ans/2+ans%2-cnt;
            if(ans%2){
                x--;
            }
            b[++top].first=x;
            b[top].second=a[i].second;
            a[i].first-=x+ans%2;
            while(a[i].first>=b[top].first&&top!=0){
                if(a[i].second!=b[top].second){
                    num+=b[top].first;
                }
                a[i].first-=b[top].first;
                top--;
            }
            cnt=ans;
            if(a[i].second!=b[top].second){
                num+=a[i].first;
            }
            b[top].first-=a[i].first;
        }
    }
    cout<<num;
    return 0;
}
