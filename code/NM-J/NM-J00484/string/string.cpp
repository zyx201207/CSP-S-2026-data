#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string6.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<int>ai;
    vector<char>ci;
    for(int i=0;i<n;i++){
        int a=0;
        char c=0;
        cin>>a>>c;
        ai.push_back(a);
        ci.push_back(c);
    }
    long long num=0;
    int left=0,right=n-1;
    while(left<right){
            if(ci[left]!=ci[right]){
                num+=min(ai[left],ai[right]);
            }
            int l=ai[left];
            ai[left]=ai[left]-min(ai[left],ai[right]);
            ai[right]=ai[right]-min(l,ai[right]);
            if(ai[left]==0){
                left++;
            }
            if(ai[right]==0){
                right--;
            }
    }
    cout<<num;
    return 0;
}
