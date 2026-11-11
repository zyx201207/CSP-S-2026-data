#include<bits/stdc++.h>
using namespace std;
long long l,c,sum=0;
pair<int ,char> a;
a q[10000];
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>l;
for(int i=0;i<l;i++){
    cin>>q[i].first>>q[i].second;
    c+=q[i].first;
}
    for(int i=0,j=l;i<n/2;i++,j--){
        if(q[i].second==q[j].second){
            sum+=abs(q[i].first-q[j].first);
        }
        else{
            sum+=min(q[i].first,q[j].first)*2;
            if(q[i].first>q[j].first){
                q[i].first=(q[i].first-q[j].first);
                i--;
            }
            else{
                q[j].first=(q[j].first-q[i].first);
                j++;
            }
        }
    }
cout<<sum;
return 0;
}

