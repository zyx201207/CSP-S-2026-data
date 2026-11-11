#include<bits/stdc++.h>
using namespace std;
pair<long long,char>a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        ans+=a[i].first;
    }
    if(n==1){
            cout<<0;
        return 0;
    }
    bool old=(ans%2==1);
    long long nans=0,half=ans/2;
    long long ed;
    for(int i=1;i<=n;i++){
        nans+=a[i].first;
        if(nans-old==half){
            ed=i;
            if(old){
                a[ed].first=a[ed].first-1;
            }
            break;
        }
        if(nans-old>half){
            ed=i;
            for(int j=n;j>=ed+1;j--){
                a[j+1].first=a[j].first;
                a[j+1].second=a[j].second;
            }
            a[ed+1].first=nans-half-old;
            a[ed+1].second=a[ed].second;
            a[ed].first=half-(nans-a[ed].first);
            n++;
            break;
        }
    }
    for(int i=1;i<=n;i++){
       if(a[i].first==0)
       {
           for(int j=i;j<=n-1;j++){
                a[j].first=a[j+1].first;
                a[j].second=a[j+1].second;
           }
           n--;
           ed--;
           break;
       }
    }
  // for(int i=1;i<=n;i++){
  //     cout<<a[i].first<<" "<<a[i].second<<endl;
   // }
    //cout<<ed<<endl;
    for(int i=1;i<=ed/2;i++){
        swap(a[i].first,a[ed-i+1].first);
        swap(a[i].second,a[ed-i+1].second);
    }
    int i=1,j=ed+1;
    long long num=0;
    long long xans=0,yans=0;
    char nch='-1';
    long long nn=0;
    xans+=a[1].first;
    nch=a[1].second;
    i++;
    nn=a[1].first;
    while(xans!=half||yans!=half){
        if(xans==yans){
           // cout<<"dz"<<endl;
            xans+=a[i].first;
            nch=a[i].second;
            nn=a[i].first;
            i++;
        }
        else if(yans>xans){
            while(yans>xans){
                    //cout<<"dx"<<endl;
                if(a[i].second!=nch){
                    num+=min(nn,a[i].first);
                }
                if(nn>a[i].first){
                    nn-=a[i].first;
                }
                else if(a[i].first>nn){
                    nch=a[i].second;
                    nn=a[j].first-nn;
                }
                else
                {
                    nn=0;
                }
                xans+=a[i].first;
                i++;
            }
        }
        while(yans<xans){
            //cout<<"dy"<<endl;
            if(a[j].second!=nch){
                num+=min(nn,a[j].first);
            }
            if(nn>a[j].first){
                nn-=a[j].first;
            }
            else if(a[j].first>nn){
                nch=a[j].second;
                nn=a[j].first-nn;
            }
            yans+=a[j].first;
            j++;
        }
    }
    cout<<num;
    return 0;
}
