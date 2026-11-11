#include<bits/stdc++.h>
using namespace std;
using LL = long long;
priority_queue<int,vector<int>,greater<int>> pq;
int n,finally=1;
LL m;
long long an=0;
bool a=true;
bool b=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    vector<LL> arr(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]!=i+1)a=false;
        if(i>3&&(arr[i]-arr[i-1])!=(arr[i-1]-arr[i-2]))b=false;
    }
    if(a || b){
        if(a){
            an=1;
        }
        if(b){
            an=arr[1]-arr[0];
        }
        for(int i=1;i<n;i++){
            if(m-an*i>=0){
                m-=an*i;
                finally++;
            }
            else{
                break;
            }
        }
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        LL chance=m;
        int cnt=0;
        for (int j=i;j>0;j--){
            if(chance-(arr[i]-arr[j])>=0){
                chance-=(arr[i]-arr[j]);
                ++cnt;
            }
            else{
                break;
            }
        }
        finally=max(finally,cnt);
    }
    cout<<finally;
}
