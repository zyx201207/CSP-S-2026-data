#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct ac{
    long long sum;
    char c;
};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long asum=0;
    vector<ac> l,l1;
    while(n--){
        long long a;
        char c;
        cin>>a>>c;
        asum+=a;
        if(l.size()==0)l.push_back({a,c});
        else if(l[l.size()-1].c==c)l[l.size()-1].sum+=a;
        else l.push_back({a,c});
    }
    l1=l;
    reverse(l1.begin(),l1.end());
    long long ans=0,li=0,ri=0;

    //cout<<asum<<' '<<l.size()<<endl;
    while(li+ri<l.size()){
        //cout<<li<<':'<<l[li].c<<"--"<<l[li].sum<<"  "<<l.size()-ri-1<<':'<<l1[ri].c<<"--"<<l1[ri].sum<<endl;
        if(l1[ri].c==l[li].c){
            if(l[li].sum==l1[ri].sum){
                ans+=l[li].sum;
                li++;
                ri++;
            }else if(l[li].sum>l1[ri].sum){
                ans+=l1[ri].sum;
                l[li].sum-=l1[ri].sum;
                ri++;
            }else{
                ans+=l[li].sum;
                l1[ri].sum-=l[li].sum;
                li++;
            }
        }else{
            if(l[li].sum==l1[ri].sum){
                li++;
                ri++;
            }else if(l[li].sum>l1[ri].sum){
                l[li].sum-=l1[ri].sum;
                ri++;
            }else{
                l1[ri].sum-=l[li].sum;
                li++;
            }
        }

    }
    //cout<<li<<"--"<<ri<<"  "<<l1[ri].c<<"--"<<l[li].c<<endl;
    if((asum)/2-ans+l[max(li, (long long)(l.size()-ri-1))].sum<0)cout<<0<<endl;
    else cout<<(asum)/2-ans+l[max(li, (long long)(l.size()-ri-1))].sum<<endl;
    return 0;
}
