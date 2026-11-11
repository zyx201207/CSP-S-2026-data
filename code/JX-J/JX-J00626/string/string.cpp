#include <bits/stdc++.h>
using namespace std;
int n,k;long long ans,sum;
struct node{
    int tot;
    char id;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].tot>>s[i].id;
        sum+=s[i].tot;
    }
    long long tmp=0,cnt=0;
    while(tmp<=sum/2){
        k++;
        tmp+=s[++cnt].tot;
    }
    int l=1,r=k;
    while(l<k&&r<=n){
        if(s[l].tot>s[r].tot){
            if(s[l].id!=s[r].id)
            ans+=s[r].tot;
            s[l].tot-=s[r].tot;
            r++;
        }
        else if(s[l].tot<s[r].tot){
            if(s[r].id!=s[l].id)
            ans+=s[l].tot;
            s[r].tot-=s[l].tot;
            l++;
        }
        else{
            if(s[r].id!=s[l].id)
            ans+=s[r].tot;
            l++;r++;

        }
    }
    cout<<ans;
	return 0;
}
