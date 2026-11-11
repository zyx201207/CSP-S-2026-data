#include<bits/stdc++.h>
using namespace std;
int l;
vector<char> s;
vector<char> v;
int a[100001];
char b[100001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>l;
    for(int i=0;i<l;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i];j++)
        {
            s.push_back(b[i]);
            v.push_back(b[i]);
        }
    }
    bool t=1;
    for(int i=0;i<l-1;i++){
        if(b[i]!=b[i+1]){
            t=0;
            break;
        }
    }
    if(t==1){
        cout<<0;
    }else{
        reverse(s.begin(),s.end());
        int sum=0;
        for(int i=0;i<s.size()/2;i++){
            if(v[i]!=s[i]){
                sum++;
            }
        }
        cout<<sum;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
