#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct _data{
    long long cnt;
    char c;
};
vector<_data> vec;
long long n;
char f(int pos){
    for (int i=n;i>=1;i--){
        if (vec[i-1].cnt<pos) return vec[i].c;
    }

}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vec.push_back({0,' '});
    long long sum=0,ans=0;
    cin>>n;
    for (int i=0;i<n;i++){
        char b;
        long long a;
        cin>>a>>b;
        vec.push_back({a+sum,b});
        sum+=a;
    }
    for (int i=1;i<=ceil(sum/2.0);i++){
        if (f(i)!=f(sum-i+1)) ans++;
    }
    cout<<ans;
    return 0;
}

