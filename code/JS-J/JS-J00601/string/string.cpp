#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],len,ans;
stack<pair<char,int>>stl,str;
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    int i=0,j=n+1,l=0,r=len+1,mid;
    if(len%2==0){
        mid=len/2;
    }
    else{
        mid=len/2+1;
    }
    while(i<j&&l<=mid&&r>=mid){
        i++;
        j--;
        l+=a[i];
        r-=a[j];
        if(i>j){
            break;
        }
        else if(l>mid){
            stl.push(make_pair(c[i],a[i]-l+mid));
            str.push(make_pair(c[j],a[j]));
            str.push(make_pair(c[i],l-mid));
        }
        else if(r<mid){
            stl.push(make_pair(c[i],a[i]));
            stl.push(make_pair(c[i],mid-r));
            str.push(make_pair(c[i],a[i]-mid+r));
        }
        else{
            stl.push(make_pair(c[i],a[i]));
            str.push(make_pair(c[j],a[j]));
        }
        while((!stl.empty())&&(!str.empty())){
            auto lt=stl.top(),rt=str.top();
            stl.pop();
            str.pop();
            if(lt.first!=rt.first){
                ans+=min(lt.second,rt.second);
            }
            if(lt.second>rt.second){
                stl.push(make_pair(lt.first,lt.second-rt.second));
            }
            else if(lt.second<rt.second){
                str.push(make_pair(rt.first,rt.second-lt.second));
            }
        }
    }
    cout<<ans;
    return 0;
}
